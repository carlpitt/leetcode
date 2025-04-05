mod all_ancestors_of_a_node_in_a_directed_acyclic_graph_2192;
mod count_number_of_nice_subarrays_1248;
mod crawler_log_folder_1598;
mod fibonacci_number_0509;
mod find_center_of_star_graph_1791;
mod find_k_pairs_with_smallest_sums_0373;
mod find_the_winner_of_the_circular_game_1823;
mod group_anagrams_0049;
mod grumpy_bookstore_owner_1052;
mod intersection_of_two_arrays_ii;
mod ipo_0502;
mod longest_consecutive_sequence_0128;
mod longest_continuous_subarray_with_absolute_diff_less_than_or_equal_to_limit_1438;
mod maximum_total_importance_of_roads_2285;
mod minimum_difference_between_largest_and_smallest_value_in_three_moves_1509;
mod minimum_increment_to_make_array_unique_0945;
mod minimum_number_of_days_to_make_m_bouquets_1482;
mod minimum_number_of_k_consecutive_bit_flips_0995;
mod minimum_number_of_moves_to_seat_everyone_2037;
mod most_profit_assigning_work_0826;
mod number_of_arithmetic_triplets_2367;
mod number_of_islands_0200;
mod pass_the_pillow_2582;
mod patching_array_0330;
mod product_of_array_except_self_0238;
mod remove_duplicates_from_sorted_array_0026;
mod remove_max_number_of_edges_to_keep_graph_fully_traversable_1579;
mod sort_an_array_0912;
mod sort_array_by_increasing_frequency_1636;
mod sort_colors_0075;
mod sort_the_jumbled_numbers_2191;
mod sort_the_people_2418;
mod split_array_into_fibonacci_sequence_0842;
mod sum_of_square_numbers_0633;
mod three_consecutive_odds_1550;
mod two_sum_0001;
mod water_bottles_1518;

#[allow(clippy::too_many_lines)]
fn main() {
    println!(
        "{:?}",
        ipo_0502::Solution::find_maximized_capital(
            2,
            0,
            vec![1, 2, 3],
            vec![0, 1, 1]
        )
    );
    println!(
        "{:?}",
        ipo_0502::Solution::find_maximized_capital(
            3,
            0,
            vec![1, 2, 3],
            vec![0, 1, 2]
        )
    );

    println!(
        "{:?}",
        minimum_increment_to_make_array_unique_0945::Solution::min_increment_for_unique(vec![
            1, 2, 2
        ])
    );
    println!(
        "{:?}",
        minimum_increment_to_make_array_unique_0945::Solution::min_increment_for_unique(vec![
            3, 2, 1, 2, 1, 7
        ])
    );

    println!(
        "{:?}",
        minimum_number_of_moves_to_seat_everyone_2037::Solution::min_moves_to_seat(
            vec![3, 1, 5],
            vec![2, 7, 4]
        )
    );
    println!(
        "{:?}",
        minimum_number_of_moves_to_seat_everyone_2037::Solution::min_moves_to_seat(
            vec![4, 1, 5, 9],
            vec![1, 3, 2, 6]
        )
    );
    println!(
        "{:?}",
        minimum_number_of_moves_to_seat_everyone_2037::Solution::min_moves_to_seat(
            vec![2, 2, 6, 6],
            vec![1, 3, 2, 6]
        )
    );

    let mut v0 = [2, 0, 2, 1, 1, 0];
    sort_colors_0075::Solution::sort_colors(&mut v0);
    println!("{v0:?}");
    let mut v1 = [2, 0, 1];
    sort_colors_0075::Solution::sort_colors(&mut v1);
    println!("{v1:?}");

    println!(
        "{:?}",
        split_array_into_fibonacci_sequence_0842::Solution::split_into_fibonacci("1101111")
    );
    println!(
        "{:?}",
        split_array_into_fibonacci_sequence_0842::Solution::split_into_fibonacci(
            "112358130"
        )
    );
    println!(
        "{:?}",
        split_array_into_fibonacci_sequence_0842::Solution::split_into_fibonacci("0123")
    );

    println!(
        "{:?}",
        patching_array_0330::Solution::min_patches(&[1, 3], 6)
    );
    println!(
        "{:?}",
        patching_array_0330::Solution::min_patches(&[1, 5, 10], 20)
    );
    println!(
        "{:?}",
        patching_array_0330::Solution::min_patches(&[1, 2, 2], 5)
    );

    println!(
        "{:?}",
        sum_of_square_numbers_0633::Solution::judge_square_sum(5)
    );
    println!(
        "{:?}",
        sum_of_square_numbers_0633::Solution::judge_square_sum(3)
    );

    println!(
        "{:?}",
        number_of_arithmetic_triplets_2367::Solution::arithmetic_triplets(
            vec![0, 1, 4, 6, 7, 10],
            3
        )
    );
    println!(
        "{:?}",
        number_of_arithmetic_triplets_2367::Solution::arithmetic_triplets(
            vec![4, 5, 6, 7, 8, 9],
            2
        )
    );

    println!(
        "{:?}",
        two_sum_0001::Solution::two_sum(vec![2, 7, 11, 15], 9)
    );
    println!("{:?}", two_sum_0001::Solution::two_sum(vec![3, 2, 4], 6));
    println!("{:?}", two_sum_0001::Solution::two_sum(vec![3, 3], 6));

    println!(
        "{:?}",
        most_profit_assigning_work_0826::Solution::max_profit_assignment(
            &[2, 4, 6, 8, 10],
            &[10, 20, 30, 40, 50],
            vec![4, 5, 6, 7]
        )
    );
    println!(
        "{:?}",
        most_profit_assigning_work_0826::Solution::max_profit_assignment(
            &[85, 47, 57],
            &[24, 66, 99],
            vec![40, 25, 25]
        )
    );

    println!(
        "{:?}",
        minimum_number_of_days_to_make_m_bouquets_1482::Solution::min_days(
            &[1, 10, 3, 10, 2],
            3,
            1
        )
    );
    println!(
        "{:?}",
        minimum_number_of_days_to_make_m_bouquets_1482::Solution::min_days(
            &[1, 10, 3, 10, 2],
            3,
            2
        )
    );
    println!(
        "{:?}",
        minimum_number_of_days_to_make_m_bouquets_1482::Solution::min_days(
            &[7, 7, 7, 7, 12, 7, 7],
            2,
            3
        )
    );

    println!(
        "{:?}",
        grumpy_bookstore_owner_1052::Solution::max_satisfied(
            &[1, 0, 1, 2, 1, 1, 7, 5],
            &[0, 1, 0, 1, 0, 1, 0, 1],
            3
        )
    );
    println!(
        "{:?}",
        grumpy_bookstore_owner_1052::Solution::max_satisfied(&[1], &[0], 1)
    );

    println!(
        "{:?}",
        count_number_of_nice_subarrays_1248::Solution::number_of_subarrays(
            &[1, 1, 2, 1, 1],
            3
        )
    );
    println!(
        "{:?}",
        count_number_of_nice_subarrays_1248::Solution::number_of_subarrays(
            &[2, 4, 6],
            1
        )
    );
    println!(
        "{:?}",
        count_number_of_nice_subarrays_1248::Solution::number_of_subarrays(
            &[2, 2, 2, 1, 2, 2, 1, 2, 2, 2],
            2
        )
    );

    println!(
        "{:?}",
        find_k_pairs_with_smallest_sums_0373::Solution::k_smallest_pairs(
            &[1, 7, 11],
            &[2, 4, 6],
            3
        )
    );
    println!(
        "{:?}",
        find_k_pairs_with_smallest_sums_0373::Solution::k_smallest_pairs(
            &[1, 1, 2],
            &[1, 2, 3],
            2
        )
    );

    println!("{:?}", longest_continuous_subarray_with_absolute_diff_less_than_or_equal_to_limit_1438::Solution::longest_subarray(&[8,2,4,7], 4));
    println!("{:?}", longest_continuous_subarray_with_absolute_diff_less_than_or_equal_to_limit_1438::Solution::longest_subarray(&[10,1,2,4,7,2], 5));
    println!("{:?}", longest_continuous_subarray_with_absolute_diff_less_than_or_equal_to_limit_1438::Solution::longest_subarray(&[4,2,2,2,4,4,2,2], 0));

    println!("{:?}", minimum_number_of_k_consecutive_bit_flips_0995::Solution::min_k_bit_flips(vec![0,1,0], 1));
    println!("{:?}", minimum_number_of_k_consecutive_bit_flips_0995::Solution::min_k_bit_flips(vec![1,1,0], 2));
    println!("{:?}", minimum_number_of_k_consecutive_bit_flips_0995::Solution::min_k_bit_flips(vec![0,0,0,1,0,1,1,0], 3));

    println!(
        "{:?}",
        find_center_of_star_graph_1791::Solution::find_center(vec![
            vec![1, 2],
            vec![2, 3],
            vec![4, 2]
        ])
    );
    println!(
        "{:?}",
        find_center_of_star_graph_1791::Solution::find_center(vec![
            vec![1, 2],
            vec![5, 1],
            vec![1, 3],
            vec![1, 4]
        ])
    );

    println!(
        "{:?}",
        group_anagrams_0049::Solution::group_anagrams(vec![
            "eat".into(),
            "tea".into(),
            "tan".into(),
            "ate".into(),
            "nat".into(),
            "bat".into()
        ])
    );
    println!(
        "{:?}",
        group_anagrams_0049::Solution::group_anagrams(vec![String::new()])
    );
    println!(
        "{:?}",
        group_anagrams_0049::Solution::group_anagrams(vec!["a".into()])
    );

    println!(
        "{:?}",
        maximum_total_importance_of_roads_2285::Solution::maximum_importance(
            5,
            vec![
                vec![0, 1],
                vec![1, 2],
                vec![2, 3],
                vec![0, 2],
                vec![1, 3],
                vec![2, 4]
            ]
        )
    );
    println!(
        "{:?}",
        maximum_total_importance_of_roads_2285::Solution::maximum_importance(
            5,
            vec![vec![0, 3], vec![2, 4], vec![1, 3]]
        )
    );

    println!("{:?}", all_ancestors_of_a_node_in_a_directed_acyclic_graph_2192::Solution::get_ancestors(8, vec![vec![0,3],vec![0,4],vec![1,3],vec![2,4],vec![2,7],vec![3,5],vec![3,6],vec![3,7],vec![4,6]]));
    println!("{:?}", all_ancestors_of_a_node_in_a_directed_acyclic_graph_2192::Solution::get_ancestors(5, vec![vec![0,1],vec![0,2],vec![0,3],vec![0,4],vec![1,2],vec![1,3],vec![1,4],vec![2,3],vec![2,4],vec![3,4]]));

    println!("{:?}", remove_max_number_of_edges_to_keep_graph_fully_traversable_1579::Solution::max_num_edges_to_remove(4, vec![vec![3,1,2],vec![3,2,3],vec![1,1,3],vec![1,2,4],vec![1,1,2],vec![2,3,4]]));
    println!("{:?}", remove_max_number_of_edges_to_keep_graph_fully_traversable_1579::Solution::max_num_edges_to_remove(4, vec![vec![3,1,2],vec![3,2,3],vec![1,1,4],vec![2,1,4]]));
    println!("{:?}", remove_max_number_of_edges_to_keep_graph_fully_traversable_1579::Solution::max_num_edges_to_remove(4, vec![vec![3,2,3],vec![1,1,2],vec![2,3,4]]));

    println!(
        "{:?}",
        three_consecutive_odds_1550::Solution::three_consecutive_odds(&[
            2, 6, 4, 1
        ])
    );
    println!(
        "{:?}",
        three_consecutive_odds_1550::Solution::three_consecutive_odds(&[
            1, 2, 34, 3, 4, 5, 7, 23, 12
        ])
    );

    println!(
        "{:?}",
        intersection_of_two_arrays_ii::Solution::intersect(
            &[1, 2, 2, 1],
            &[2, 2]
        )
    );
    println!(
        "{:?}",
        intersection_of_two_arrays_ii::Solution::intersect(
            &[4, 9, 5],
            &[9, 4, 9, 8, 4]
        )
    );

    println!("{:?}", minimum_difference_between_largest_and_smallest_value_in_three_moves_1509::Solution::min_difference(vec![5,3,2,4]));
    println!("{:?}", minimum_difference_between_largest_and_smallest_value_in_three_moves_1509::Solution::min_difference(vec![1,5,0,10,14]));
    println!("{:?}", minimum_difference_between_largest_and_smallest_value_in_three_moves_1509::Solution::min_difference(vec![3,100,20]));

    println!(
        "{:?}",
        product_of_array_except_self_0238::Solution::product_except_self(&[
            1, 2, 3, 4
        ])
    );
    println!(
        "{:?}",
        product_of_array_except_self_0238::Solution::product_except_self(&[
            -1, 1, 0, -3, 3
        ])
    );

    println!(
        "{:?}",
        longest_consecutive_sequence_0128::Solution::longest_consecutive(vec![
            100, 4, 200, 1, 3, 2
        ])
    );
    println!(
        "{:?}",
        longest_consecutive_sequence_0128::Solution::longest_consecutive(vec![
            0, 3, 7, 2, 5, 8, 4, 6, 0, 1
        ])
    );

    println!(
        "{:?}",
        pass_the_pillow_2582::Solution::pass_the_pillow(4, 5)
    );
    println!(
        "{:?}",
        pass_the_pillow_2582::Solution::pass_the_pillow(3, 2)
    );

    println!(
        "{:?}",
        water_bottles_1518::Solution::num_water_bottles(9, 3)
    );
    println!(
        "{:?}",
        water_bottles_1518::Solution::num_water_bottles(15, 4)
    );

    println!(
        "{:?}",
        find_the_winner_of_the_circular_game_1823::Solution::find_the_winner(
            5, 2
        )
    );
    println!(
        "{:?}",
        find_the_winner_of_the_circular_game_1823::Solution::find_the_winner(
            6, 5
        )
    );

    println!(
        "{:?}",
        crawler_log_folder_1598::Solution::min_operations(vec![
            "d1/".into(),
            "d2/".into(),
            "../".into(),
            "d21/".into(),
            "./".into()
        ])
    );
    println!(
        "{:?}",
        crawler_log_folder_1598::Solution::min_operations(vec![
            "d1/".into(),
            "d2/".into(),
            "./".into(),
            "d3/".into(),
            "../".into(),
            "d31/".into()
        ])
    );
    println!(
        "{:?}",
        crawler_log_folder_1598::Solution::min_operations(vec![
            "d1/".into(),
            "../".into(),
            "../".into(),
            "../".into()
        ])
    );

    let mut nums = [1, 1, 2];
    let k =
        remove_duplicates_from_sorted_array_0026::Solution::remove_duplicates(
            &mut nums,
        );
    println!("{k:?}, {nums:?}");
    let mut nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4];
    let k =
        remove_duplicates_from_sorted_array_0026::Solution::remove_duplicates(
            &mut nums,
        );
    println!("{k:?}, {nums:?}");

    /*println!(
        "{:?}",
        number_of_islands_0200::Solution::num_islands(vec![
            vec!['1', '1', '1', '1', '0'],
            vec!['1', '1', '0', '1', '0'],
            vec!['1', '1', '0', '0', '0'],
            vec!['0', '0', '0', '0', '0']
        ])
    );
    println!(
        "{:?}",
        number_of_islands_0200::Solution::num_islands(vec![
            vec!['1', '1', '0', '0', '0'],
            vec!['1', '1', '0', '0', '0'],
            vec!['0', '0', '1', '0', '0'],
            vec!['0', '0', '0', '1', '1']
        ])
    );*/

    println!(
        "{:?}",
        sort_the_people_2418::Solution::sort_people(
            vec!["Mary".into(), "John".into(), "Emma".into()],
            vec![180, 165, 170]
        )
    );
    println!(
        "{:?}",
        sort_the_people_2418::Solution::sort_people(
            vec!["Alice".into(), "Bob".into(), "Bob".into()],
            vec![155, 185, 150]
        )
    );

    println!(
        "{:?}",
        sort_array_by_increasing_frequency_1636::Solution::frequency_sort(
            vec![1, 1, 2, 2, 2, 3]
        )
    );
    println!(
        "{:?}",
        sort_array_by_increasing_frequency_1636::Solution::frequency_sort(
            vec![2, 3, 1, 3, 2]
        )
    );
    println!(
        "{:?}",
        sort_array_by_increasing_frequency_1636::Solution::frequency_sort(
            vec![-1, 1, -6, 4, 5, -6, 1, 4, 1]
        )
    );

    println!(
        "{:?}",
        sort_the_jumbled_numbers_2191::Solution::sort_jumbled(
            &[8, 9, 4, 0, 2, 1, 3, 5, 7, 6],
            &[991, 338, 38]
        )
    );
    println!(
        "{:?}",
        sort_the_jumbled_numbers_2191::Solution::sort_jumbled(
            &[0, 1, 2, 3, 4, 5, 6, 7, 8, 9],
            &[789, 456, 123]
        )
    );

    println!(
        "{:?}",
        sort_an_array_0912::Solution::sort_array(vec![5, 2, 3, 1])
    );
    println!(
        "{:?}",
        sort_an_array_0912::Solution::sort_array(vec![5, 1, 1, 2, 0, 0])
    );

    println!("{:?}", fibonacci_number_0509::Solution::fib(2));
    println!("{:?}", fibonacci_number_0509::Solution::fib(3));
    println!("{:?}", fibonacci_number_0509::Solution::fib(4));
}
