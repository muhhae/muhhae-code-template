const router = require('express').Router();
const verifyToken = require('../controllers/auth');

const {
    signup,
    getUsers,
    getUser,
    signin
} = require('../controllers/userController');

router.post('/sign-up', signup)
router.post("/sign-in", signin)
router.get("/users", verifyToken, getUsers)
router.get("/user", verifyToken, getUser)

module.exports = router