#define DLL_NAME "kernel32.dll"
unsigned long gvar = 0;
void PrintAddress() {
	printf("PrintAddress的地址:%p \n", PrintAddress);
	gvar++;
}
int main(){  
	HINSTANCE handle;
	handle = LoadLibrary(DLL_NAME);
	if (!handle) {
	       printf(" load dll erro !");  exit(0);
	} 
	printf("Kernel32.dll文件库的地址： 0x%x\n", handle);
	void *pvAddress = GetProcAddress(handle, "LoadLibraryW");
	printf("LoadLibrary函数地址：%p \n", pvAddress);
	PrintAddress();
	printf("变量gvar的地址：%p \n", &gvar);
	system("pause");
	return 0;
}
