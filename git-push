#!/bin/bash

if [ -z "$1" ]; then
	  echo "Usage: git-auto-push.sh <commit-message>"
	    exit 1
fi

REPO_DIR="$(git rev-parse --show-toplevel)"
cd "$REPO_DIR"
git add .
git commit -m "$1"
git push
