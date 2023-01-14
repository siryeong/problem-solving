class Solution {
public:
    const int MOD = 1000000007;
    const long long MODL = 1000000007ll;
    const int LEFT = 0;
    const int RIGHT = 1;
    
    int number_count[10001][10];
    int acc_number[2][10001][10];
    
    int hash_table[2][10001][100];
    int acc_hash[2][10001][100];
    
    int reverse[100];
    
    int countPalindromes(string s) {
        for(int i = 0; i < 10; i++) for(int j = 0; j < 10; j++)
            reverse[i*10 + j] = j*10 + i;
        
        // 숫자 count 세기
        for(int i = 0; i < s.length(); i++)
            number_count[i][s[i] - '0']++;
        
        // 숫자 count 누적
        for(int i = 0; i < s.length(); i++) for(int j = 0; j < 10; j++)
            acc_number[LEFT][i][j] = (i==0 ? 0:acc_number[LEFT][i-1][j]) + number_count[i][j];
        
        for(int i = s.length()-1; i >= 0; i--) for(int j = 0; j < 10; j++){
            acc_number[RIGHT][i][j] 
                = (i==(s.length()-1) ? 0 : acc_number[RIGHT][i+1][j]) + number_count[i][j];
        }
            
        
        
        // hash 갯수 세기
        for(int i = 1; i < s.length()-1; i++) for(int j = 0; j < 10; j++){
            hash_table[LEFT][i][j * 10 + s[i] - '0'] 
                = (hash_table[LEFT][i][j * 10 + s[i] - '0'] 
                   + acc_number[LEFT][i-1][j]) % MOD;
            
            hash_table[RIGHT][i][(s[i] - '0')*10 + j] 
                = (hash_table[RIGHT][i][(s[i] - '0')*10 + j] 
                   + acc_number[RIGHT][i+1][j]) % MOD;
        }
        
        // hash 갯수 누적
        for(int i = 0; i < s.length(); i++) for(int j = 0; j < 100; j++)
            acc_hash[LEFT][i][j] = ((i==0?0:acc_hash[LEFT][i-1][j]) + hash_table[LEFT][i][j]) % MOD;
        
        for(int i = s.length()-1; i >= 0; i--) for(int j = 0; j < 100; j++)
            acc_hash[RIGHT][i][j] = ((i==(s.length()-1)?0:acc_hash[RIGHT][i+1][j]) + hash_table[RIGHT][i][j]) % MOD;
        
        // 정답 도출
        int answer = 0;
        for(int i = 2; i < (int)s.length()-2; i++) {
            for(int j = 0; j < 100; j++){
                answer = (answer + (int)(((long long)acc_hash[0][i-1][j] * (long long)acc_hash[1][i+1][reverse[j]]) % MODL))%MOD;
            }
        }
        return answer;
    }
};