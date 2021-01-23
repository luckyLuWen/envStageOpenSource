package cn.envStage.service;

import cn.envStage.domain.User;

public interface UserService {
    /**
     * 登陆用户
     * @param user
     * @return
     */

    User login(User user);
}
