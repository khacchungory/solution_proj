#include <iostream>

using namespace std;
long int arr[100000];
int n = -1;
int ans = -1;
int t;
void add(int number, int p){
    n++;
    for(int i = n; i > p; i--){
        arr[i] = arr[i-1];
    }
    arr[p] = number;
//    cout<<"day moi"<<endl;
//    for(int i=0; i<=n; i++){
//        cout<<arr[i]<<" ";
//    }
//    cout<<endl;
}
void del(int p){
    if(p == n){
        n--;
        return;
    }
    for(int i = p; i < n; i++){
        arr[i] = arr[i+1];
    }
    n--;
}
void getMedianNumber(){
    if(n == 0){
        ans = arr[0];
        n--;
        return;
    }
    if((n+1) % 2 == 0){
        int x = (n+1)/2;
        int index = arr[x] < arr[x-1] ? x : x-1;
        ans = arr[index];
        del(index);
    }else{
        int x = (n+1)/2;
        ans = arr[x];
        del(x);
    }
}
void binary(int d, int c, int v){
    if(d > c)
        return;
    int x = (c-d+1)/2;
    x+=d;
    if(arr[x] <=v && arr[x+1] >= v){
        add(v, x+1);
        return;
    }else if(arr[x-1] <=v && arr[x] >= v){
        add(v, x);
        return;
    }else if(arr[x] < v){
        binary(x+1, c, v);
    }else{
        binary(d, x, v);
    }
}
int main()
{
    scanf("%d", &t);
    int tmp;
    while(t > 0){
        scanf("%d", &tmp);;
        switch(tmp){
            case 0:
                t--;
                n = -1;
                break;
            case -1:
                if(n >= 0){
                    getMedianNumber();
                    printf("%d\n", ans);;
                }
                break;
            default:
                if(n == -1 || tmp >= arr[n]){
                    n++;
                    arr[n] = tmp;
                }else if(tmp <= arr[0]){
                    add(tmp, 0);
                }else {
                    binary(0, n, tmp);
                }
        }
    }
    return 0;
}
// 1
// 54
// 57
// 73
// 68
// 90
// 15
//  2
//  9
// 56
// 41
// 60
// 75
// 85
// 95
// -1
// -1
// -1
//  3
// 91
// 40
// 62
// 61
// 55
// 13
// 37
// 12
//100
// 49
// 66
// 98
// 88
// 79
// 43
// 63
//  7
// 33
// 29
// 52
// 93
// 11
// 38
// 36
// 76
// 48
// 67
// 65
// 72
// 53
// 30
// 78
// 24
//  5
// 81
// 44
// 45
// 34
// 32
// 46
// -1
// -1
// -1
// 27
// 87
// 94
// 80
// 77
// 25
// 82
//  6
// 71
// 21
// 59
// 14
// 31
//  8
// 16
// 99
// 19
// 26
//  4
// 58
// 10
// 69
// 47
// 96
// 20
// 84
// 35
// 70
// -1
// -1
// -1
// 50
// 74
// 22
// 86
// 42
// 13
// 66
// 74
// 32
// 63
// 38
// 39
// 92
// 76
// 59
// 50
// 34
//  2
// 17
// 97
// 57
// 28
// 65
// 46
// 10
// 60
// 26
//  5
// 19
// 99
// 72
// 80
// 52
// 79
// 43
//  4
// 69
// 24
// 54
// 73
//  6
// 88
// 33
// 62
//100
// 44
// 78
// 47
//  9
// 30
// 94
// 14
//  1
// 42
// 31
// 89
// 58
// 71
// -1
// -1
// -1
// 23
// 86
// 27
// 91
//  3
// 36
// 45
// 22
// 67
// 61
// 64
// 49
// 56
// 85
// 95
// 21
// 37
// 11
// 96
// 81
// 68
// 25
//  7
// 51
// 29
//  8
// 87
// -1
// -1
// -1
// 13
// 66
// 74
// 32
// 63
// 38
// 39
// 92
// 76
// 59
// 50
// 34
//  2
// 17
// 97
// 57
// 28
// 65
// 46
// 10
// 60
// 26
//  5
// 19
// 99
// 72
// 80
// 52
// 79
// 43
//  4
// 69
// 24
// 54
// 73
//  6
// 88
// 33
// 62
//100
// 44
// 78
// 47
//  9
// 30
// 94
// 14
//  1
// 42
// 31
// 89
// 58
// 71
// 23
// 86
// 27
// 91
//  3
// 36
// 45
// 22
// 67
// 61
// 64
// 49
// 56
// 85
// 95
// 21
// 37
// 11
// 96
// 78
// 60
// 30
// 42
// 57
// 19
// 50
// 45
// 46
// 93
//  7
// 34
// 35
// 52
// 44
// 83
// 88
// 48
// 73
// 58
// 51
// 37
// 38
// 59
// 41
// 72
// 90
// 82
// 25
// 76
//  1
// 55
// 31
//100
// 84
// 75
// 22
// 28
// 10
// 26
// 71
// 36
// 65
// 70
// 39
// 69
// 23
// 18
// 86
// 13
// 14
// 77
// 49
//  3
// 17
//  8
// 15
// 61
//0
// 15
// 79
// 38
// 93
// 90
// 59
// 58
// 62
// 39
// 98
//100
// 82
// 34
// 53
// 55
// 80
// 89
// 13
// 36
// 32
// 70
// 43
// 26
// 71
// 66
// 29
// 14
// 52
// 64
// 28
// 75
// 94
//  2
//  5
// 50
// 85
// 63
// 68
// 83
// 67
// 41
//  1
// 95
// 88
// 11
// 30
// 92
// 40
// 54
// 86
// 35
// 57
// 37
//  4
// 96
// 84
// 91
// 44
// 12
// 81
// 49
//  3
//  8
// 23
// 31
// 72
// 22
// 99
//  6
// 19
// 60
// 87
// 74
// 47
// 61
// 25
// 56
// 24
// 51
// 18
//  7
// 77
// 45
// 65
// 10
// 73
// 78
// 76
// 16
// 48
// 17
// 69
// 21
// 27
// 42
// 46
// 97
// 33
// 43
// 98
// 64
// 89
// 91
// 92
// 67
// 63
// 54
// 11
// 53
//  6
// 33
// 87
// 24
// 40
// 74
// 47
// 79
// 56
// 85
// 96
// 66
// 22
// 28
// 38
// 88
// 48
// 76
// 90
//  5
//  3
// 75
// 84
// 49
// 52
// 78
// 92
// 51
// 71
// 12
// 29
// 57
// 98
// 19
// 66
// 74
//  2
// 36
// 43
// 34
//  4
// 95
//  7
// 40
//  9
// 27
// 45
// 18
// 72
//  1
// 41
// 37
// 70
// 79
// 59
// 81
// 62
// 35
//100
// 42
// 99
// 32
// 24
// 68
// 47
// 60
// 50
// 56
// 21
// 82
// 87
// 91
// 94
// 15
// 44
// 55
// 31
//  6
// 26
// 69
// 64
// 58
// 39
// 46
// 33
// 93
// 65
// 11
// 61
// 89
// 73
// 86
// 23
// 30
// 96
// 13
// 67
// 10
// 85
// 17
// 97
// 20
// 16
// 25
// 14
// 54
// 63
// 83
// 77
// 53
//  8
// 80
// 95
// 68
//  2
// 94
// 21
// 99
// 20
// 12
// 80
//  9
// 16
// 81
// 29
// 97
//  4
// 27
// 62
// 32
//  5
// 81
// 68
// 25
//  7
// 51
// 29
//  8
// 87
// 83
// 84
// 15
// 82
// 35
// 41
// 90
// 77
// 12
// 98
// 16
// 93
// 70
// 55
// 18
// 48
// 20
// 75
// 40
// 53
// 83
// 84
// 15
// 82
// 35
// 41
// 90
// 77
// 12
// 98
// 16
// 93
// 70
// 55
// 18
// 48
// 20
// 75
// 40
// 53
// 18
// 97
// 89
// 17
// 39
//  1
// 28
// 51
// 23
// 83
// 92
// 64
// -1
// -1
// -1
// -1
// -1
// -1
// -1
// 0

#include <iostream>
#include <queue>
 
#define ll long long
 
using namespace std;
 
int main(int argc, const char * argv[])
{
    ll t;
    scanf(" %lld", &t);
    
    for (ll i = 0; i < t; i++)
    {
        priority_queue<ll> max_heap;
        priority_queue <ll, vector<ll>, greater<ll> > min_heap;
        ll inp;
        scanf(" %lld", &inp);
        
        max_heap.push(inp);
        
        ll n;
        scanf(" %lld", &n);
        
        while (n != 0)
        {
            ll length_max_heap = max_heap.size();
            ll length_min_heap = min_heap.size();
            ll median;
            
            if (length_max_heap > length_min_heap)
                median = max_heap.top();
            else if (length_max_heap < length_min_heap)
                median = min_heap.top();
            else
                if (length_max_heap == 0 and length_min_heap == 0)
                {
                    max_heap.push(n);
                    scanf(" %lld", &n);
                    continue;
                }
                else
                    median = min(max_heap.top(), min_heap.top());
                            
            if (n == -1)
            {
                printf("%lld\n", median);
            
                if (length_max_heap == 0)
                    min_heap.pop();
                else if (length_min_heap == 0)
                    max_heap.pop();
                else if (max_heap.top() == median)
                    max_heap.pop();
                else
                    min_heap.pop();
                scanf(" %lld", &n);
                continue;
            }
            
                    
            if (n >= median)
            {
                if (length_max_heap >= length_min_heap)
                    min_heap.push(n);
                else if (length_max_heap < length_min_heap)
                {
                    max_heap.push(min_heap.top());
                    min_heap.pop();
                    min_heap.push(n);
                }
            }
            
            else
            {
                if (length_max_heap <= length_min_heap)
                    max_heap.push(n);
                else if (length_max_heap > length_min_heap)
                {
                    min_heap.push(max_heap.top());
                    max_heap.pop();
                    max_heap.push(n);
                }
            }
            
            scanf(" %lld", &n);
        }
    }
}
 