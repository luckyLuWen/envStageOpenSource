package cn.envStage.service.impl;

import cn.envStage.dao.DevicesNumDao;
import cn.envStage.dao.impl.DevicesNumDaoImpl;
import cn.envStage.domain.Devices_num;
import cn.envStage.service.DevicesNumService;


public class DevicesNumServiceImpl implements DevicesNumService {

    private DevicesNumDao devicesNumDao = new DevicesNumDaoImpl();

    @Override
    public Devices_num getDevicesNum() {
        return devicesNumDao.findAllDevicesNum();
    }
}
