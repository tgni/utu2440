#! /bin/bash
echo "creatint rootfs dir......"
mkdir rootfs
cd rootfs

echo "making dir : bin dev etc lib proc sbin sys usr"
mkdir bin dev etc lib proc sbin sys usr #必备的8个目录
mkdir usr/bin usr/lib usr/sbin lib/modules

# Don't use mknod ,unless you run this Script as root !
# mknod -m 600 dev/console c 5 1
# mknod -m 666 dev/null c 1 3


echo "making dir : mnt tmp var"
mkdir mnt tmp var
chmod 1777 tmp
mkdir mnt/etc mnt/jffs2 mnt/yaffs mnt/data mnt/temp
mkdir var/lib var/lock var/log var/run var/tmp 
chmod 1777 var/tmp

echo "making dir : home root boot"
mkdir home root boot

cd dev/
su
mknod -m 600 console c 5 1;mknod -m 666 null c 1 3;exit;exit

echo "done"
