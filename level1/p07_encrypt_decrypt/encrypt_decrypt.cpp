//ֱ�� ^ ��Ϊ���ܽ��ܷ����ɣ��Ͼ���level1���� 
#include<stdio.h>
#include<cstring>
const int maxn = 20;

void encrypt_decrypt(const char* to_encrypt, const char* key, char* result){
	for(int i = 0; i< maxn; i++)
		result[i] = to_encrypt[i] ^ key[i%strlen(key)];		//ѭ���Ƚ�ûë�� 
}


int main(){
	char to_encrypt[maxn], output[maxn], key[maxn];
	printf("�����벻����%dλ��������ַ���\n", maxn);
	scanf("%s", to_encrypt); 
	printf("�����벻����%dλ�����룬�Լ����볬��ԭ�Ĳ��ֻᱻ�ӵ� ��ͷ\n", maxn);
	scanf("%s", key);
	
	encrypt_decrypt(to_encrypt, key, output);
	printf("���ܺ��ַ���Ϊ%s\n", output);
	printf("�������������\n"); 
	scanf("%s", key);		//ĬĬ�ӵ�ԭ��Կ��
	encrypt_decrypt(output, key, to_encrypt);	//ĬĬ�ӵ�ԭ���ַ��� 
	printf("���ܺ��ַ���Ϊ%s\n", to_encrypt); 
	return 0;
}
