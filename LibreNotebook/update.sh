#!/bin/bash

cp build/main.pdf LibreNotebook.pdf
cp LibreNotebook.pdf \
  ~/projects/archive/archive.enochyu.com/static/LibreNotebook.pdf

cd ~/projects/archive/archive.enochyu.com

rm -r public
hugo

git switch web
git add .
git commit -S -m "feat(web): Update LibreNotebook"
git push origin web

