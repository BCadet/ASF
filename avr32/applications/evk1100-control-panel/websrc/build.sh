#!/bin/sh
#
# Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
#

rm -f WebServerGraph.tgz
rm -f ../DATAFLASH_CONTENT/WEB/*
perl compact.pl
cp -r mochi ../DATAFLASH_CONTENT/WEB/.
cp *.gif *.jpg *.png *.ico ../DATAFLASH_CONTENT/WEB/.
cd ../DATAFLASH_CONTENT/WEB
dos2unix *.htm
cd ../../WEBSRC
gtar cvfz WebServerGraph.tgz *
