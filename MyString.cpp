#include <cstdio>
#include <cstring>

class MyString {
public:
	MyString(char* pData = NULL);
	~MyString(void);
	MyString(const MyString& other);

	MyString& operator=(const MyString& str);

	void Print();
	
private:
	char* m_pData;
};

MyString::MyString(char* pData) {
	if(pData == NULL) {
		m_pData = new char[1];
		*m_pData = '\0';	
	}
	else {
		int length = strlen(pData);
		m_pData = new char[length+1];
		strcpy(m_pData, pData);
	}
}

MyString::MyString(const MyString& other) {
	int length = strlen(other.m_pData);
	m_pData = new char[length+1];
	strcpy(m_pData, other.m_pData);
}

MyString::~MyString() {
	delete[] m_pData;
}

MyString& MyString::operator=(const MyString& other) {
	if(&other == this) {
		return *this;
	}
	delete[] m_pData;
	m_pData = NULL;
	
	m_pData = new char[ strlen(other.m_pData) + 1 ];
	strcpy(m_pData, other.m_pData);

	return *this;
}

void MyString::Print() {
	printf("%s\n", m_pData);
}

int main() {
	MyString str1, str3;
	str1.Print();
	char* text = "hello world";
	MyString str2(text);
	str2.Print();
	str3 = str1 = str2;
	str1.Print();
	str1 = str1;
	str1.Print();
	str3.Print();

	return 0;
}
