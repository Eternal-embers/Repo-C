#include<iostream>
using namespace std;

int sum[50][50];
int dp[50][50];
int main()
{
    int n,m;
    cin>>n>>m;
    char s[50];
    cin>>(s+1);

    for(int i=1;i<=n;i++)
    {
        sum[i][i] = s[i]-'0';
        for(int j=i+1;j<=n;j++)
        {
            sum[i][j] = sum[i][j-1]*10+s[j]-'0';
        }
    }

    for(int i=1;i<=n;i++) dp[i][0] = sum[1][i];//ǰi������û�г˺� = ǰi����

    for(int k=1;k<=m;k++)//�˺ŵĸ���
    {
        for(int l=1;l<=n;l++)    //���䳤��
        {
            for(int i=1;i<=l;i++) //ͨ��i�ֿ�l���� ���������һ���˺�
            {
                dp[l][k] = max(dp[l][k],dp[i][k-1]*sum[i+1][l]);
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}
