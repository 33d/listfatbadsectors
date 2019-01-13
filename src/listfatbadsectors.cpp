#include "core/FatSystem.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {

	if (argc < 2) {
		fprintf(stderr, "Lists all sectors of a FAT filesystem "
			"marked bad.\n"
			"Specify the filename of an image\n");
		exit(1);
	}

	FatSystem fat(argv[1]);
	if (!fat.init()) {
		fprintf(stderr, "init");
		exit(1);
	}

	for (int cluster = 2; cluster < fat.totalClusters; cluster++) {
		if (fat.nextCluster(cluster) == FAT_LAST) {
			unsigned long long addr = fat.clusterAddress(cluster);
			printf("%lld\n", addr / fat.bytesPerSector);
		}
	}

	return 0;
}

