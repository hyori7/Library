#include "main.h"

int main()
{
	Library *newLib = new Library();
	FileIO *fileIO = new FileIO(newLib, "catalogue.txt", "members.txt");
	
	fileIO->importCatalogueData();
	fileIO->importMemberData();
	
	TextInterface *ui = new TextInterface(newLib);
	
	fileIO->exportCatalogueData();
	fileIO->exportMemberData();
	
	return 0;
}