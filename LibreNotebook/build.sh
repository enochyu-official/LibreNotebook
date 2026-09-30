#!/bin/bash

OUT_DIR="$HOME/projects/LibreNotebook/librenotebook.enochyu.com"
TMP_DIR="$HOME/projects/LibreNotebook/LibreNotebook/temp"
CONTENT="$OUT_DIR/content"
CSS="$OUT_DIR/assets/css/make4ht"

rm -r "$CONTENT" "$CSS"
mkdir "$CONTENT" "$CSS"

# Preface
make4ht -u -B temp -f html5+tidy tex/preface.tex "mathjax"
tidy -indent -wrap 70 -utf8 -m temp/preface.html
mv temp/preface.html "$CONTENT"
mv temp/preface.css "$CSS"

# Notes
for dir in tex/*; do
  [[ -d "$dir" ]] || continue

  dirName="${dir#tex}"
  mkdir -p "$CONTENT$dirName"

  for subdir in "$dir"/*; do
    [[ -d "$subdir" ]] || continue

    (
      cd "$HOME/projects/LibreNotebook/LibreNotebook/$subdir"

      subdirName="${subdir#"$dir"}"
      mkdir "$CONTENT$dirName$subdirName"

      for file in *.tex; do
        fileName="$(basename "$file" .tex)"

        make4ht -u -B "$TMP_DIR" -f html5+tidy "$fileName".tex "mathjax"
        tidy -indent -wrap 70 -utf8 -m "$TMP_DIR/$fileName".html
        mv "$TMP_DIR/$fileName".html "$CONTENT$dirName$subdirName"
        mv "$TMP_DIR/$fileName".css "$CSS"
      done
    )
  done
done

cd "$HOME/projects/LibreNotebook/LibreNotebook/"
mv temp/*.svg "$OUT_DIR"static/svg/
rm -r temp/


