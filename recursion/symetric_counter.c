void symetric_counter(int number)
{
  if(number == 0)
  {
    return;
  }

  printf("%d\n", number);
  symetric_counter(--number);
  printf("%d\n", number);
}
