// #define __LINUX__ 1;

#include <stdio.h>
#include <iostream>
//#include "../include/m5apiw32.h"
#include "schunk_libm5api/m5apiw32.h"


int main( void )
{	
	int i = 0;
	int ret = 0;
	unsigned long serNo = 0;
	int dev = 0;
//	char strInitString[] = "RS232:1,9600";
//	char strInitString[] = "RS232:2,9600";
// 	char strInitString[] = "ESD:0,250";
	char strInitString[] = "PCAN:/dev/pcan33,500";

	printf("\n\n");
	printf( "Console Test Program for PowerCube\n" );
	printf( "Version 1.0, (c) Amtec GmbH 2005\n" );
	printf( "----------------------------------\n\n ");
// 
	ret = PCube_openDevice( &dev, strInitString );
// 	printf( "PCube_openDevice() returned: %d\n", ret);
// 	if( ret == 0 )
// 	{
// 		for( i = 1; i < MAX_MODULES; i++ )
// 		{
// 			ret = PCube_getModuleSerialNo( dev, i, &serNo );
// 			if( ret == 0 )
// 				printf( "Found module %d with SerialNo %d\n", i, (int)serNo);
// 	
// 		}
// 	}
// 	else
// 	{	
// 		printf( "Unable to open Device! error %d\n", ret );
// 		return 0;
// 	}
// 	ret = PCube_closeDevice( dev );
	return 0;
}