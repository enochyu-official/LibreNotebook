const workerUrl = 'https://librenotebook-view-counter-db.enochyu.workers.dev';
const pageUrl = window.location.href;
const viewCountEl = document.getElementById('view-count');

if (viewCountEl) {
  fetch(`${workerUrl}/?url=${encodeURIComponent(pageUrl)}`)
    .then(response => {
      if (!response.ok) throw new Error(`HTTP error! status: ${response.status}`);
      return response.json();
    })
    .then(data => {
      if (data.error) throw new Error(data.error);
      viewCountEl.textContent = `${data.count}`;
    })
    .catch(error => {
      console.error('Error fetching view count:', error);
      viewCountEl.classList.add('error');
      viewCountEl.textContent = `Total Visits: Error (${error.message})`;
    });
}

