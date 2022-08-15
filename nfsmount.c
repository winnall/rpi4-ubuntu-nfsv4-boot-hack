/**
 *
 * Work-around for Debian NFSv3 restriction when doing a network boot on Raspberry Pi
 *
 * Thanks due to Trent W Buck (trentbuck@gmail.com) for the original solution
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/mount.h>

int main( int argc, char **argv ) {

	fprintf(
		stderr,
		"nfsmount:"
	       );
	for( int a = 0; a < argc; a++ ) {
		fprintf(
			stderr,
			" %s",
			argv[ a ]
		       );
	}
	fprintf(
		stderr,
		"\n"
	       );

	if ( mount(
			"192.168.8.20:/RPi4/Ubuntu/jammy/root",
			"/root",
			"nfs",
			0,
			"nfsvers=4,addr=192.168.8.20,rw,nolock,retrans=10"
		  ) ) {

		fprintf(
			stderr,
			"errno = %d\n",
			errno
		       );
	}

}
