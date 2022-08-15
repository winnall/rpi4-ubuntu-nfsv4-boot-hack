# rpi4-ubuntu-nfsv4-boot-hack
A hacked `nfsmount` to enable network booting of Ubuntu via NFSv4 on an RPi4

The `nfsmount` delivered with the Ubuntu 22.04 image for Raspberry Pi only works with NFSv3. This is because of an upstream (Debian) bug which has been known about since 2007, would you believe? By modifying the file `nfsmount.c` to match your requirements you can created your own `nfsmount`, which will network boot the RPi4 using NFSv4. Clearly, this is a hack.

Proceed as follows on Ubuntu 22.04:

1) `sudo apt install libklibc-dev`;
1) modify `nfsmount.c` to match your environment;
2) `klcc -o nfsmount nfsmount.c`;
3) copy `nfsmount` to `/usr/lib/klibc/bin/nfsmount` (you might like to save the existing Ubuntu-delivered `nfsmount` first);
4) `sudo update-initramfs -u` (this will generate errors - I ignore them);
5) `sudo lsinitramfs -l /boot initrd.img | less` (to ensure that your `nfsmount` has been installed);
6) reboot.

This is not a thing of beauty, but it does a specific job.
