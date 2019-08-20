#!/bin/sh

sed -i 's/dl-cdn.alpinelinux.org/mirrors.aliyun.com/g' /etc/apk/repositories && \
	apk add make gcc g++ qt5-qtbase-dev && \
	cd /tmp/qt && \
	make clean && \
	make distclean && \
	rm -f *.o && \
	rm -f disk-free-space && \
	qmake-qt5 && \
	make && \
	./disk-free-space
