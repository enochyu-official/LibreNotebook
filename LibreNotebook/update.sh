#!/bin/bash

cp LibreNotebook.pdf \
  ~/websites/archive.enochyu.com/static/LibreNotebook.pdf

cd ~/websites/archive.enochyu.com

tmp=$(mktemp)
jq ".[-1].date = \"$(date '+%-d %B %Y')\"" data/math04.json > "$tmp" \
  && mv "$tmp" data/math04.json

tmp=$(mktemp)
jq ".[-1].date = \"$(date '+%-d %B %Y')\"" data/featured.json > "$tmp" \
  && mv "$tmp" data/featured.json

tmp=$(mktemp)
jq ".[0].date = \"$(date '+%-d %B %Y') - Last Updated\"" \
  data/disciplines.json > "$tmp" && mv "$tmp" data/disciplines.json

rm -r public
hugo

git add .
git commit -S -m "Update LibreNotebook"
git push origin main

