
#include <Windows.h>
#include <stdio.h>

extern "C" unsigned int __stdcall Supports()
{
	return 544;
}

#define DECR_TABLE_MEM 0x4CECE8
//#define DECR_TABLE_MEM 0x4C88E0
//#define DECR_FUNC_MEM 0x46A6F0

extern "C" bool __stdcall Load(void **data)
{
	int i = 0;
	char buffer[10];
	FILE *output = fopen("table.txt", "a");

	if(output)
	{
		fprintf(output, "BYTE decrypt_table[] = {");
		for(; i < 256; i++)
		{
			//printf("%02X,", ((BYTE*)DECR_TABLE_MEM)[i]); // printf sux
			fprintf(output, "%02X,", ((BYTE*)DECR_TABLE_MEM)[i]);
		}
		fprintf(output, "};");
		fclose(output);
	}
	return true;
}
