
#include <random>
#include <iostream>

using namespace std;

#define int long long

// 30 bit size with +7 to make it a prime number
int mod = 1e9 + 7;
int g = 5;


int getrand(int l, int r)
{
  // generates random number from range [l, r]
  std::random_device rd;  // obtain a random number
  std::mt19937 gen(rd()); 
  std::uniform_int_distribution<> distr(l, r);
  return distr(gen);
}

int bin_exp(int a, int b, int c)// algorithm 
{
  if (b == 0)
  {
    return 1;
  }
  int t = bin_exp(a, b / 2, c);
  if (b % 2)
  {
    return t * t % c * a % c;
  }
  else
    return t * t % c;
}

pair<int, int> generate_key()
{
  int private_key = getrand(1, mod - 1);
  int public_key = bin_exp(g, private_key, mod);
  return {private_key, public_key};
}

pair<int, int> encrypt(int message, int public_key)
{
  int secret = getrand(1, mod - 1);
  int sh_secret = bin_exp(public_key, secret, mod);
  //chipher text 1
  int c1 = bin_exp(g, secret, mod);
  //chipher text 2
  int c2 = message * sh_secret % mod;
  return {c1, c2};
}

int decrypt(int c1,int c2, int private_key)
{
  int sh_secret = bin_exp(c1, private_key, mod);
  // inverse multiplaction
  int inverse = bin_exp(sh_secret, mod - 2, mod);
  int message = c2 * inverse % mod;
  return message;
}



signed main()
{
  int private_key = 0;
  int public_key = 0;
  int Y1 = 0; // cipher text 1
  int Y2 = 0; // cipher text 2

  cout<< " ***** Generating Key ***** \n";
  pair<int, int> key = generate_key();
  private_key = key.first;
  public_key = key.second;
  cout << "Private key: " << private_key << "\n";
  cout << "Public key: " << public_key << "\n";


  cout<<"\n ***** Encryption ***** \n";
  cout << "Enter your message (a number between 1 and " << mod << "): ";
  // int message = 101; // debuging TESTING ONLY
  int message; //messasge 
  cin >> message;
  cout << "Enter public key of receiver: ";
  // int public_key;
  // cin >> public_key;
  pair<int, int> encrypted_message = encrypt(message, public_key);
  Y1 = encrypted_message.first;
  Y2 = encrypted_message.second;
  cout << "\n Cipher text 1:" << Y1<< "\n";   // ciphertext 1
  cout << " Chiper text 2:" << Y2<< "\n"; // ciphertext 2


  cout<< "\n ***** Decryption ***** \n";

  int dmessage = decrypt(Y1,Y2, private_key);
  cout << "Decrypted message: " << dmessage << "\n";

  return 0;
}