#!/bin/sh
cat /u/all/astek/public/passwd | cut -d : -f 5 | grep -w "bon" | wc -l | sed "s/ //g"