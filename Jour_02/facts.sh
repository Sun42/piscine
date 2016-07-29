#!/bin/sh
cat /u/all/astek/public/passwd | egrep "ept1|prof" | sed 's/ept1/newbee/g' | sed 's/prof/gentil/g'