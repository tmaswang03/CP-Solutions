/*
 * MIT License
 *
 * Copyright (c) 2020 Adam Chen
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
/**
 * Reference Ascii Table
 * Dec  Char                           Dec  Char     Dec  Char     Dec  Char
 * ---------                           ---------     ---------     ----------
 *   0  NUL (null)                      32  SPACE     64  @         96  `
 *   1  SOH (start of heading)          33  !         65  A         97  a
 *   2  STX (start of text)             34  "         66  B         98  b
 *   3  ETX (end of text)               35  #         67  C         99  c
 *   4  EOT (end of transmission)       36  $         68  D        100  d
 *   5  ENQ (enquiry)                   37  %         69  E        101  e
 *   6  ACK (acknowledge)               38  &         70  F        102  f
 *   7  BEL (bell)                      39  '         71  G        103  g
 *   8  BS  (backspace)                 40  (         72  H        104  h
 *   9  TAB (horizontal tab)            41  )         73  I        105  i
 *  10  LF  (NL line feed, new line)    42  *         74  J        106  j
 *  11  VT  (vertical tab)              43  +         75  K        107  k
 *  12  FF  (NP form feed, new page)    44  ,         76  L        108  l
 *  13  CR  (carriage return)           45  -         77  M        109  m
 *  14  SO  (shift out)                 46  .         78  N        110  n
 *  15  SI  (shift in)                  47  /         79  O        111  o
 *  16  DLE (data link escape)          48  0         80  P        112  p
 *  17  DC1 (device control 1)          49  1         81  Q        113  q
 *  18  DC2 (device control 2)          50  2         82  R        114  r
 *  19  DC3 (device control 3)          51  3         83  S        115  s
 *  20  DC4 (device control 4)          52  4         84  T        116  t
 *  21  NAK (negative acknowledge)      53  5         85  U        117  u
 *  22  SYN (synchronous idle)          54  6         86  V        118  v
 *  23  ETB (end of trans. block)       55  7         87  W        119  w
 *  24  CAN (cancel)                    56  8         88  X        120  x
 *  25  EM  (end of medium)             57  9         89  Y        121  y
 *  26  SUB (substitute)                58  :         90  Z        122  z
 *  27  ESC (escape)                    59  ;         91  [        123  {
 *  28  FS  (file separator)            60  <         92  \        124  |
 *  29  GS  (group separator)           61  =         93  ]        125  }
 *  30  RS  (record separator)          62  >         94  ^        126  ~
 *  31  US  (unit separator)            63  ?         95  _        127  DEL
 */
#include <bits/stdc++.h>
#include <unistd.h>
#pragma GCC target ("avx2")
#pragma message("Compiling at: " __TIMESTAMP__ ". Executing File: " __FILE__ ". If this date is not the same as the submission date, it could be an indication that the submission was rejudged.")
#ifdef NDEBUG
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif
#pragma GCC target("avx,avx2,fma")
using namespace std;
#define pb push_back
#define ll long long
#define lp pair<ll,ll>
#define ld long double
#define ms(a,b) memset(a,b,sizeof(a));
// ORZ Template 2.1 | DO NOT modify these lines! clion will crash! | IO Operations: > read < write >= read line
static struct IO {
#define pstr(x) for (char i: x)pc(i);
#define likely(x) __builtin_expect(x,true)
#define unlikely(x) __builtin_expect(x,false)
    const int buffer_size = 1 << 24;
    const static bool line_buf;
    unsigned char *read_buffer = new unsigned char[buffer_size];
    unsigned char *write_buffer = new unsigned char[buffer_size];
    int read_length = 0, read_index = 0, write_index = 0;
    bool eof = false;

#ifdef _getchar_nolock
#define ugc _getchar_nolock
#else
#define ugc getchar_unlocked
#endif
    inline unsigned char gc() {
#ifndef _UNISTD_H
        if(line_buf){
            return ugc();
        }
#endif
        if (unlikely(read_index >= read_length)) {
            if (unlikely(eof)) return EOF;
            fill_buffer();
        }
        return read_buffer[read_index++];

    }

    inline void pc(char x) {
        if (unlikely(write_index >= buffer_size)) flush_buffer();
        write_buffer[write_index] = x;
        write_index++;
    }

    inline void fill_buffer() {
        if(line_buf){
            // this is called when _UNISTD_H is available
            read_length = read(STDIN_FILENO, read_buffer, buffer_size);
            read_index = 0;
        }else{
            auto x = fread(read_buffer, sizeof(char), buffer_size, stdin);
            if (unlikely(x != 0 && x < buffer_size)) eof = true;
            read_length = x;
            read_index = 0;
        }
    }

    inline void flush_buffer() {
        fwrite(write_buffer, sizeof(char), write_index, stdout);
        fflush(stdout);
        write_index = 0;
    }

    ~IO() {
        flush_buffer();
    }

    // read

    template<typename T>
    inline void next_int(T &val) {
        val = 0;
        int c = gc();
        while (c <= ' ') c = gc();
        bool n = (c == '-');
        if (n) c = gc();
        do { val = val * 10 + c - '0'; } while ((c = gc()) >= '0' && c <= '9');
        if (n) val = -val;
    }
    template<typename T>
    inline void next_decimal(T &val) {
        val = 0;
        T div = 1;
        int c = gc();
        while (c <= ' ') c = gc();
        bool n = (c == '-');
        if (n)c = gc();
        do { val = val * 10 + c - '0'; } while ((c = gc()) >= '0' && c <= '9');
        if (c == '.') { while ((c = gc()) >= '0' && c <= '9')val += (c - '0') / (div *= 10); }
        if (n) val = -val;
    }
    inline void next_token(string &s) {
        ostringstream oss;
        int c = gc();
        while (c <= ' ') c = gc();
        do {
            oss << static_cast<char>(c);
        } while ((c = gc()) > ' ');
        s = oss.str();
    }

    inline void next_ln(string &s) {
        ostringstream oss;
        int c;
        while ((c = gc()) != EOF) {
            if (c == '\n') break;
            oss << static_cast<char>(c);
        }
        s = oss.str();
    }

    // write

    const unsigned ll num_map[20] = {9,
                                     99,
                                     999,
                                     9999,
                                     99999,
                                     999999,
                                     9999999,
                                     99999999,
                                     999999999,
                                     9999999999,
                                     99999999999,
                                     999999999999,
                                     9999999999999,
                                     99999999999999,
                                     999999999999999,
                                     9999999999999999,
                                     99999999999999999,
                                     999999999999999999,
                                     9999999999999999999ULL,
                                     ULLONG_MAX};

    inline int fast_log10(const unsigned long long& val) const{
        for(int i = 0; i < 20; i++){
            if(val <= num_map[i]) return i;
        }
    }
    char buf[65];
    template<typename T>
    inline void write_int(T& data){
        if(data == 0) pc('0');
        else{
            int len = 0;
            if(data < 0){
                pc('-');
                len = fast_log10(-data) + 1;
            }else{
                len = fast_log10(data) + 1;
            }
            get_chars_int(data, len, buf);
            for(int i = 0; i < len; i++){
                pc(buf[i]);
            }
        }
    }

    // jdk implementation

    static inline char digit_10s(unsigned long long r){
        return (r/10) + '0';
    }
    static inline char digit_1s(unsigned long long r){
        return (r%10) + '0';
    }

    static inline void get_chars_int(unsigned long long i, int index, char* buf) {
        unsigned long long q, r;
        int charPos = index;

        // Generate two digits per iteration
        while (i >= 65536) {
            q = i / 100;
            // really: r = i - (q * 100);
            r = i - ((q << 6) + (q << 5) + (q << 2));
            i = q;
            buf [--charPos] = digit_1s(r);
            buf [--charPos] = digit_10s(r);
        }

        // Fall thru to fast mode for smaller numbers
        // assert(i <= 65536, i);
        for (;;) {
            q = (i * 52429) >> (16+3);
            r = i - ((q << 3) + (q << 1));  // r = i-(q*10) ...
            buf [--charPos] = r + '0';
            i = q;
            if (i == 0) break;
        }
    }

    /*input*/
    inline IO &operator>(char &s) {
        s = gc();
        return *this;
    }

    inline IO &operator>(string &s) {
        next_token(s);
        return *this;
    }

    inline IO &operator>(ld &s) {
        next_decimal(s);
        return *this;
    }

    inline IO &operator>(ll &s) {
        next_int(s);
        return *this;
    }

    inline IO &operator>(int &s) {
        next_int(s);
        return *this;
    }

    inline IO &operator>=(string &s) {
        next_ln(s);
        return *this;
    }

    /*output*/
    inline IO &operator<(const int &s) {
        write_int(s);
        return *this;
    }

    inline IO &operator<(const ll &s) {
        write_int(s);
        return *this;
    }

    inline IO &operator<(const ld &s) {
        pstr(to_string(s));
        return *this;
    }

    inline IO &operator<(const string &s) {
        pstr(s);
        return *this;
    }

    inline IO &operator<(const char &s) {
        pc(s);
        return *this;
    }

    IO() {
        if(line_buf){
            cin.sync_with_stdio(false); cin.tie(nullptr);
        }else{
            setvbuf(stdin, NULL, _IONBF, 0);
        }
        setvbuf(stdout, NULL, _IONBF, 0);
    }
}io;
/*IO Operations: > read < write >= read line*/
inline void setbit(ll &mask, int idx, bool bit){if(bit){mask = mask | (1 << idx);}else{mask = mask & ~(1 << idx);}}
inline bool getbit(ll mask, int idx) {return (mask >> idx) & 1;}
inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b);}
inline ll lcm(ll a, ll b) { return a * b / gcd(a, b);}
#define tts(x) #x
// Switches between line buffered io, and EOF buffered io. Non-lined buffered io requires EOF (Ctrl+D) on termination.
#ifdef __MINGW32__ // Local IDE
const bool IO::line_buf = true;
#else
const bool IO::line_buf = false;
#endif
const ll MM = 1e6+10;
using namespace std;
ll dp[MM], pos[MM]; //holds starting point of split
string strinq[MM];

int main()
{
    // dp[i] = min(dp[k]+max(arr[k]-arr[i]);
    ms(dp,0x3f3f3f3f);
    dp[0] = 0;
    int M, Q; io>M; io>Q;
    pair<ll, string> arr[Q+1];
    arr[0] = {0,""};
    for(int i = 1; i <= Q; ++i){
        string s; io>s;
        ll a; io>a;
        arr[i] = {a,s};
        ll max1 = arr[i].first, optpos;
        for(int k = 1; k<=min(i,M); ++k){
            if(dp[i-k]+max1<dp[i]){
                dp[i] = dp[i-k]+max1;
                optpos = i-k+1;
            }
            max1 = max(max1, arr[i-k].first);
        }
        pos[i] = optpos;
    }

    io<"Total Time: ";
    io<dp[Q]; io<"\n";
    ll i = Q, cur = 0;
    while(i >= 1){
        ll optpos = pos[i];
        string tempstr = "";
        for(ll k = max(1LL,optpos); k <= i; ++k){
            tempstr+=arr[k].second;
            tempstr+=" ";
        }
        tempstr+="\n";
        i=optpos-1;
        strinq[cur]=tempstr;
        ++cur;
    }
    for(int i = cur; i >= 0; --i){
        io<strinq[i];
    }
    return 0;
}
