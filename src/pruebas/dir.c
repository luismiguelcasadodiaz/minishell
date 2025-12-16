#include <stdio.h>
#include <dirent.h>

int main(int ac, char **av)
{
	struct dirent	*parentDir;
	DIR *pDir;

	if(ac !=2)
	{
		printf("Invalid argument");
		return (-1);
	}
	pDir = opendir(av[1]);
	if(pDir == NULL)
	{
		printf("No se puede abrir el directorio %s\n", av[1]);
		return (1);
	}
	while((parentDir=readdir(pDir)) != NULL)
		printf("[%s]\n",parentDir->d_name);
	closedir(pDir);
	return (1);
}

/*
int main()
{
	DIR *folder;

	folder = opendir(".");
	if (folder == NULL)
	{
		printf("No se puede leer el directorio");
		return (1);
	}
	else
	{
		printf("Directorio abierto");
	}
	closedir(folder);
	return(0);
}*/
