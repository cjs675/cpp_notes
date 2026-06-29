int add(int x, int y) 
{
    return x + y;
}

int add(int x, int y) // violation of ODR, we've already defined function add(int, int) 
{
    return x + y;
}

int main() 
{
    int x{};
    int x{ 5 }; // violation of ODR, we've alreayd defined x 
}
