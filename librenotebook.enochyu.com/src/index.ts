export interface Env {
  DB: D1Database;
}

export default {
  async fetch(request: Request, env: Env): Promise<Response> {
    const url = new URL(request.url);
    const pageUrl = url.searchParams.get('url');

    const allowedOrigins = [
      'http://localhost:1313', 
      'https://librenotebook.enochyu.com',
    ];

    const origin = request.headers.get('Origin');

    const corsHeaders = origin && allowedOrigins.includes(origin)
      ? {
          'Access-Control-Allow-Origin': origin,
          'Access-Control-Allow-Methods': 'GET, OPTIONS',
          'Access-Control-Allow-Headers': 'Content-Type',
          'Content-Type': 'application/json',
        }
      : { 'Content-Type': 'application/json' };
    if (request.method !== 'OPTIONS' && origin && !allowedOrigins.includes(origin)) {
      return new Response(JSON.stringify({ error: 'Origin not allowed' }), { status: 403, headers: corsHeaders });
    }
    if (request.method === 'OPTIONS') {
      return new Response(null, { status: 204, headers: corsHeaders });
    }
    if (!pageUrl) {
      return new Response(JSON.stringify({ error: 'URL parameter is required' }), { status: 400, headers: corsHeaders });
    }
    try {
      const { results } = await env.DB.prepare('SELECT count FROM ViewCounter WHERE url = ?').bind(pageUrl).all();
      if (results.length === 0) {
        await env.DB.prepare('INSERT INTO ViewCounter (url, count) VALUES (?, 1)').bind(pageUrl).run();
        return new Response(JSON.stringify({ url: pageUrl, count: 1 }), { headers: corsHeaders });
      } else {
        await env.DB.prepare('UPDATE ViewCounter SET count = count + 1 WHERE url = ?').bind(pageUrl).run();
        const updated = await env.DB.prepare('SELECT count FROM ViewCounter WHERE url = ?').bind(pageUrl).first();
        return new Response(JSON.stringify({ url: pageUrl, count: updated.count }), { headers: corsHeaders });
      }
    } catch (error) {
      return new Response(JSON.stringify({ error: 'Database error', details: error.message }), { status: 500, headers: corsHeaders });
    }
  },
};

