# rpi4-ubuntu-nfsv4-boot-hack
A hacked `nfsmount` to enable network booting of Ubuntu via NFSv4 on an RPi4.

The `nfsmount` delivered with the Ubuntu 22.04 image for Raspberry Pi only works with NFSv3. This is because of an upstream (Debian) bug which has been known about since 2007, would you believe? The file `nfsmount` is a shell script that replaces `/usr/lib/klibc/bin/nfsmount` and works with NFSv4, though possibly not with NFSv3...

Don't use `nfsmount.c` any more: it is only still listed because I don't know how to delete it.

The big advantage of `nfsmount` is that it uses the parameters passed into `cmdline.txt`, which `initramfs` passes to it in the normal way. In fact, it will only use NFSv4 if you tell it to in `cmdline.txt`. I am unlikely to test this script with anything other than NFSv4. If anyone would like to let me know what happens with NFSv3 I will happily document it here.

Proceed as follows on Ubuntu 22.04:

1) copy `nfsmount` to `/usr/lib/klibc/bin/nfsmount` (you might like to save the existing Ubuntu-delivered `nfsmount` first);
2) `sudo update-initramfs -u` (this will generate errors - I ignore them);
3) `sudo lsinitramfs -l /boot initrd.img | less` (to ensure that your `nfsmount` has been installed);
4) reboot.

This is not a thing of beauty, but it does a specific job.
