void counter(int lower, int upper)
{
  if(upper == lower)
  {
    printf("%d\n", lower);
    return;
  }

  printf("%d\n", lower);

  counter(lower + 1 ,upper);
}
