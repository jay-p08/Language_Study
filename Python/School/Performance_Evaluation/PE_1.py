if __name__ == "__main__" :
    student = (
        ("가", 170),
        ("니", 165),
        ("다", 180),
        ("라", 160),
    )

    student = dict(student)

    for i in student  :
        if student.get( i ) >= 170 :
            print( i, "(", student.get( i ), ")" )