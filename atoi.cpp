#define INT_MAX (2147483647)  

#define INT_MIN (-2147483648)  

class Solution {

public:

    int atoi(const char *str) {

        if(str == NULL)

            return 0;

            

        int sign = 1;

        long long  result = 0;



             //erase zero

        while(*str == '0' || *str == ' ')

                str++;

                

         if(*str == '-')

        {

             sign = -1;

             str++;

        }else if(*str == '+')

            str++;

        

        while(*str >= '0' && *str <= '9')

        {

           result = result * 10  + (*str - '0');

                   

             if(sign * result > INT_MAX)

                    return INT_MAX;

            if(sign * result < INT_MIN)

                    return INT_MIN;

            str++;

        }

        

         return sign * result;

    }

};
