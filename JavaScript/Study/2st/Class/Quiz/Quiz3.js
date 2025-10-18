function Car(brand, year) {
    this.brand = brand;
    this.year = year;
}

Car.prototype.age = function (currentYear) {
    return currentYear - this.year;
}

const myCar = new Car("Hyundai", 2020);
console.log(myCar.age(2025)); // 5  : 2025년  5 출력