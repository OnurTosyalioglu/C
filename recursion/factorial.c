int factorial(int number)
{
  if(number == 0)
  {
    return 1;
  }

  return factorial(number - 1) * number;
}
