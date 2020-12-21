#pragma once
class Event;
class BloodUnit
{
public:
  BloodUnit(double timeblod, Event* utilize);
  ~BloodUnit() { delete utilize_blood_; utilize_blood_ = nullptr; }
  double ShelfLife; // czas przydatnosci
  Event* utilize_blood_;
};