#!/bin/sh
cat /u/all/astek/public/passwd | cut -d : -f 1,7 | grep /bin/shells/close | cut -d : -f 1

