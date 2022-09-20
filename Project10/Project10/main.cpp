#include <iostream>
#include <string>
#include <vector>

using namespace std;

class VanBan
{
private:
	string paragraph;

public:
	VanBan()
	{

	}

	VanBan(const string &st) : paragraph(st)
	{

	}

	int getNumOfWords()
	{
		int n = 0;
		for (int i = 0; i < paragraph.length(); i++)
		{
			if ((paragraph[i] == ' ') && (paragraph[i + 1] != ' '))
			{
				n++;
			}
		}

		return ++n;
	}

	int getNumOfCharsA()
	{
		int n = 0;
		for (int i = 0; i < paragraph.length(); i++)
		{
			if ((paragraph[i] == 'a') || (paragraph[i] != 'A'))
			{
				n++;
			}
		}

		return n;
	}

	void formatParagraph()
	{
		while (paragraph[0] == ' ')
		{
			paragraph.erase(paragraph.begin());
		}

		while (paragraph[paragraph.length() - 1] == ' ')
		{
			paragraph.erase(paragraph.begin() + paragraph.length() - 1);
		}

		int i = 0;

		while (i < paragraph.length())
		{
			if ((paragraph[i] == ' ') && (paragraph[i + 1] == ' '))
			{
				paragraph.erase(paragraph.begin() + i);
			}
			else i++;
		}
	}

	void printParagraph()
	{
		cout << "Van ban sau khi dinh dang la: \n" << paragraph << endl;
	}

	~VanBan()
	{

	}
};

int main()
{
	VanBan example("   Order  refers to the way you organize your supporting sentences.  Whether you choose chronological order, order of importance, or another logical   presentation of  detail, a solid  always has a definite organization. In a well-ordered paragraph, the reader follows along easily, aided by the pattern you’ve established. Order helps the reader grasp your meaning and avoid confusion.  ");
	cout << "So luong ky tu A trong van ban la: " << example.getNumOfCharsA() << endl;
	cout << "So luong tu trong van ban la: " << example.getNumOfWords() << endl;
	example.formatParagraph();
	example.printParagraph();
	return 0;
}