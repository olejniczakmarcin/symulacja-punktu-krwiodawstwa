#pragma once
class Recipient
{
public:
  Recipient(double time,double blood_needed);
private:
  double arrival_Time_; // czas nadejscia
  double blood_needed_; // zapotrzebowanie na okreslona ilosc jednostek krwi
};