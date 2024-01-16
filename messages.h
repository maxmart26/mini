/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:32:45 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/01/16 16:28:42 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# define C_ERROR "\n\033[0;91mError !\033[0m"
# define C_ARGS "\033[38;5;214mAdd the server PID and a string or smiley.\033[0m"
# define C_EX_ARGS "\033[0;92mExample : ./client 4242(PID) Hello(Message)\033[0m\n"

# define C_NOTIFICATION "Waiting for notification...\n"

# define S_PID "My PID : [%d], parameter for the client.\n\n"
# define S_WLC "I print messages sent by the client.\n"
# define S_CHEV ">> "

# define NOTIFICATION_R1 "RECE"
# define NOTIFICATION_R2 "IVED\n"

# define SA_USR1_FAIL "SIGUSR1 failed\n"
# define SA_USR2_FAIL "SIGUSR2 failed\n"

# define SERV_FAIL_USR1 "SIGUSR1"
# define SERV_FAIL_USR2 "Server failed to send SIGUSR2"

# define UNICODE "(Undefined with unicode...)\n"

#endif
