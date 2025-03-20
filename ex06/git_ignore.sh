#!/bin/bash
git ls-files -o -i --exclude-standard

# -o represents others files
# -i represents ignored files
# --exclude-standard is required for ignored because otherwise it will ignore everything
