int readNumber();

void writeAnswer(int num);

int main() {
	writeAnswer(readNumber() + readNumber());
	return 0;
}
