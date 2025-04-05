import pandas as pd


def count_unique_subjects(teacher: pd.DataFrame) -> pd.DataFrame:
    # 1.
    return (
        teacher[
            # possibly unnecessary?
            ["teacher_id", "subject_id"]
        ]
        .groupby("teacher_id")[
            # possibly unnecessary?
            "subject_id"
        ]
        .nunique()
        .reset_index(name="cnt")
    )

    # 2.
    return (
        teacher[
            # possibly unnecessary?
            ["teacher_id", "subject_id"]
        ]
        .groupby("teacher_id", as_index=False)[
            # possibly unnecessary?
            "subject_id"
        ]
        .nunique()
        .rename(columns={"subject_id": "cnt"})
    )

    # 3.
    ans = (
        teacher[
            # possibly unnecessary?
            ["teacher_id", "subject_id"]
        ]
        .groupby("teacher_id", as_index=False)[
            # possibly unnecessary?
            "subject_id"
        ]
        .nunique()
    )

    ans.rename(columns={"subject_id": "cnt"}, inplace=True)

    return ans

    # 4.
    return (
        teacher[
            # possibly unnecessary?
            ["teacher_id", "subject_id"]
        ]
        .groupby("teacher_id", as_index=False)[
            # possibly unnecessary?
            "subject_id"
        ]
        .agg(cnt=("subject_id", "nunique"))
    )
