#include <iostream>
#include <string.h>

using namespace std;

/*
  func : requesting for word , that user have to guess it
 */
string get_word()
{
  string str;
  cout << "Enter Your WORD : ";
  cin >> str;
  return str;
}

/*
  func : just showing guessed words and requesting for new char
 */
char get_char(string word, bool answer[])
{
  for (int i = 0; i < word.length(); i++) {
    if (answer[i]) {
      cout << word[i] << ' ';
    } else {
      cout << "_ ";
    }
  }
  char ch;
  cout << " : ";
  cin >> ch;
  return ch;
}

/*
  func : this function runs the game
  	user have word.legnth + 5 chance to guess the word
	each time that we want to get a new char from user , first
	we will show it to him (guessed words or _ if he didnt guessed that char)
	then will request for new char
	if given char was in the word , we will make a true flag with
	that index in answer array

  return : true if used guessed all of the words , or falls if he tried max chance
 */
bool run_game(string word)
{
  int chance = word.length() + 5;
  int guessed_words = 0;
  bool answer[word.length()];
  memset(answer, 0 , word.length() * sizeof(bool));
  char ch;
  for (int i = 0; i < chance; i++) {
    if (guessed_words == word.length())
      return true;
    ch = get_char(word, answer);

    for (int j = 0; j < word.length(); j++) {
      if (answer[j])
	continue;
      if (word[j] == ch) {
	answer[j] = true;
	guessed_words++;
	break;
      }
    }
    
  }
  return false;
}

int main()
{
  string word = get_word();
  if (run_game(word))
    cout << "You Won\n";
  else {
    cout << "Word was : '" << word << "'";
  }
  return 0;
}
