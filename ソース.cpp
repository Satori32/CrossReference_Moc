#include <iostream>
#include <vector>
#include <memory>
#include <string>

struct Concept {
	std::string C = "None";
	std::string Text = "Some";
};

typedef std::shared_ptr<Concept> SConcept;

struct Local {
	SConcept C = std::make_shared<Concept>();
	std::string LocalDara = "Hoge";
};

SConcept CreateConcept(std::string C, std::string S) {
	SConcept SC = std::make_shared<Concept>();
	SC->C = C;
	SC->Text = S;

	return SC;
}

Local MakeTicket(SConcept SC,std::string LD) {
	Local L{ SC,LD };
	return L;
}

struct Player {
	Local L{};
	std::string PS = "PLAYER STRAGE";
};

std::string& ReadLocal(Local& L) {
	return L.LocalDara;
}
bool WriteLocal(Local& L, std::string T) {
	L.LocalDara = T;
	return true;
}

int main() {
	auto X = CreateConcept("名前", "一意性を得るためのアイデンティファィア");
	Player A;
	Player B;
	auto Y = MakeTicket(X, {});
	A.L = Y;
	B.L = Y;

	WriteLocal(A.L, "私の名前はたこ焼き太郎だ。");

	return 0;
}