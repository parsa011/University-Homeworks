#include "global.h"

typedef struct {
	int len;
	int *val;
	bool negative;
} bigint;

#define INIT_BIGINT {0, NULL, false}
#define BIGINT_SIZE 10

void bigint_sum(bigint *, bigint *);
void bigint_sub(bigint *, bigint *);
void get_bigint(bigint *);
void print_bigint(bigint buf);

void bigint_print(bigint buf)
{
	if (buf.negative)
		cout << '-';
	for (int i = 0; i < buf.len; i++) {
		cout << buf.val[i];
	}
	cout << endl;
}

/*
 gets a big int until reaches to max length and return length of given number
*/
void get_bigint(bigint *buf)
{
	char ch;
	int bufsize = BIGINT_SIZE;
	buf->len = 0;
	buf->val = (int *)malloc(bufsize * sizeof(int));
	do {
		ch = getchar();
		if (ch == '\n')
			break;
		else if (ch == 0x7F) {
			if (buf->len > 0) {
				buf->val[--buf->len] = 0;
			}
		}

		if (buf->len == bufsize) {
			bufsize += BIGINT_SIZE; 
			buf->val = (int *)realloc(buf->val, bufsize * sizeof(int));
		}
		if (isdigit(ch) || ch == '-') {
			if (ch == '-') {
				if (buf->len == 0) 
					buf->negative = true;
				else {
					cout << "invalid number\n";
					exit(0);
				}
			} else {
				buf->val[buf->len] = ch - '0';
				buf->len++;
			}
		} else {
			cout << "Enter Valid Number\n";
			exit(0);
		}
	} while(true);
}

/*
  returns 1 if b is bigger
  returns -1 if a is bigger
  and 0 if both are equal
*/
int bigint_bigger(bigint *a, bigint *b)
{
#define RIGHT 1
#define LEFT -1
#define EQUAL 0
	if (!a->negative && b->negative)
		return LEFT;
	if (a->negative && !b->negative)
		return RIGHT;
	if (a->len == b->len) {
		for (int i = 0; i < a->len; i++) {
			if (a->val[i] > b->val[i])
				return LEFT;
			else if (a->val[i] < b->val[i])
				return RIGHT;
			else
				continue;
		}
		return EQUAL;
	} else {
		if (a->len > b->len)
			return LEFT;
		if (a->len < b->len)
			return RIGHT;
	}
	return EQUAL;
#undef RIGHT
#undef LEFT
#undef EQUAL
}

void bigint_sub(bigint *a, bigint *b)
{
	if (!a->negative && !b->negative) {
		bigint_sum(a, b);
		return;
	}
	bigint *bigger;
	bigint *smaller;
	/*
	  here we stored b sign , because we need to check which number is bigger
	  set a and b sign to positive , then check , and after check restore b sign
	  a sign will be bigger number sign
	*/
	bool b_sign = b->negative;
	a->negative = b->negative = false;
	int status = bigint_bigger(a, b);
	b->negative = b_sign;
	bigger = status == 1 ? b : a;
	smaller = status == -1 ? b : a;

	bool dec = false;
	string res = "";
	int i = bigger->len - 1, j = smaller->len - 1, temp;
	for (; i >= 0 || j >= 0;) {
		int n1 = bigger->val[i--];
		int n2 = j >= 0 ? smaller->val[j--] : 0;
		if (dec)
			n1--;
		if (n2 > n1) {
			dec = true;
			n1 += 10;
		}
		temp = abs(n2 - n1);
		res += to_string(temp);
	}
	reverse_string(res);
	a->len = res.length();
	a->negative = bigger->negative;
	free(a->val);
	a->val = (int *)malloc(a->len * sizeof(int));
	for (i = 0; i < res.length(); i++) {
		a->val[i] = res[i] - '0';
	}
}

void bigint_sum(bigint *a, bigint *b)
{
	if (a->negative != b->negative) {
		bigint_sub(a, b);
		return;
	}
	int new_len = max(a->len, b->len);
	int buf[new_len];
	int k = new_len - 1, temp;
	int i = a->len - 1, j = b->len - 1;
	int carry;
	for (; i >= 0 || j >= 0;) {
		int n1 = i >= 0 ? a->val[i--] : 0;
		int n2 = j >= 0 ? b->val[j--] : 0;
		temp = n1 + n2 + carry;
		carry = temp / 10;
		buf[k--] = temp % 10;
	}
	new_len = carry ? new_len + 1 : new_len;
	free(a->val);
	a->len = new_len;
	a->val = (int *)malloc(new_len * sizeof(int));
	i = j = 0;
	if (carry) {
		a->val[i++] = 1;
	}
	for (; i < new_len; i++)
		a->val[i] = buf[j++];
}

int main()
{
	bigint a = INIT_BIGINT, b = INIT_BIGINT;
	get_bigint(&a);
	get_bigint(&b);
	bigint_sum(&a, &b);
	bigint_print(a);
	return 0;
}
