#ifndef H_dateType
#define H_dateType

class dateType
{
public:
  dateType();
  void setDate(int month, int day, int year);
  int getMonth() const;
  int getDay() const;
  int getYear() const;
  void printDate() const;

private:
  int dMonth; // Month
  int dDay;   // Day
  int dYear;  // Year
};

#endif