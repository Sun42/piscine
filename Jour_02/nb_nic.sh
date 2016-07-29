#!/bin/sh
cat /u/all/astek/public/passwd | cut -d : -f 5 | grep -i sadirac | grep -i nicolas | wc -l | sed "s/ //g"