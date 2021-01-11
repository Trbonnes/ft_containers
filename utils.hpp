/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:57:55 by trbonnes          #+#    #+#             */
/*   Updated: 2021/01/11 11:20:33 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

template <typename T>
struct Equal
{
    bool operator()(const T &lhs, const T &rhs) const
    {
        return lhs == rhs;
    }
};

template <typename T>
struct Less
{
    bool operator()(const T &lhs, const T &rhs) const
    {
        return lhs < rhs;
    }
};

#endif