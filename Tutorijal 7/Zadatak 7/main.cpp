#include <iostream>
#include <set>

template <typename tip>
std::set<tip> Unija(std::set<tip> s1, std::set<tip> s2)
{
	std::set<tip> s3;
	for(tip x : s1) s3.insert(x);
	for(tip x : s2) s3.insert(x);

	return s3;
}

template <typename tip>
std::set<tip> Presjek(std::set<tip> s1, std::set<tip> s2)
{
	std::set<tip> s3;
	for(tip x : s1)
	{
		for(tip y : s2)
		{
			if(x == y) s3.insert(x);
		}
	}
	return s3;
}


int main ()
{
	std::set<std::string>s1={"ja","isao","ulicom"};
	std::set<std::string>s2={"ja","ulicom"};
	std::set<std::string>s3=Unija(s1,s2);
	std::set<std::string>s4=Presjek(s1,s2);
	std::cout<<"Unija: ";
	for(auto x : s3) std::cout<<x<<", ";
	std::cout<<std::endl;
	std::cout<<"Presjek: ";
	for(auto y : s4) std::cout<<y<<", ";
	return 0;
}
