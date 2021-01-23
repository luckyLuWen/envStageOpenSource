package cn.envStage.service.impl;

import cn.envStage.dao.UserDao;
import cn.envStage.dao.impl.UserDaoImpl;
import cn.envStage.domain.User;
import cn.envStage.service.UserService;

public class UserServiceImpl implements UserService {

    private UserDao userDao = new UserDaoImpl();

    /**
     * 登录方法
     * @param user
     * @return
     */
    @Override
    public User login(User user) {

        return userDao.findByUsernameAndPassword(user.getUserAccount(), user.getUserPassword(), user.getRole());
    }

}
