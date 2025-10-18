class Time:
    def __init__(self, hour, minute):
        self.hour = hour
        self.minute = minute
        self._normalize()

    def _normalize(self):
        if self.minute >= 60:
            self.hour += self.minute // 60
            self.minute = self.minute % 60
        if self.hour < 0 or self.minute < 0:
            self.hour, self.minute = 0, 0

    def add(self, time):
        return Time(self.hour + time.hour, self.minute + time.minute)

    def sub(self, time):
        total1 = self.hour * 60 + self.minute
        total2 = time.hour * 60 + time.minute
        diff = total1 - total2
        if diff < 0:
            return Time(0, 0)
        return Time(diff // 60, diff % 60)

    def __str__(self):
        return f"{self.hour:02d}:{self.minute:02d}"


if __name__ == "__main__":
    time1 = Time(2, 45)
    time2 = Time(1, 30)

    time3 = time1.add(time2)
    time4 = time1.sub(time2)

    print(time3)
    print(time4)
