import numpy as np

X_pattern = [
    [1, 0, 0, 0, 0, 1],
    [0, 1, 0, 0, 1, 0],
    [0, 0, 1, 1, 0, 0],
    [0, 0, 1, 1, 0, 0],
    [0, 1, 0, 0, 1, 0],
    [1, 0, 0, 0, 0, 1]
]

O_pattern = [
    [1, 1, 1, 1, 1, 1],
    [1, 0, 0, 0, 0, 1],
    [1, 0, 0, 0, 0, 1],
    [1, 0, 0, 0, 0, 1],
    [1, 0, 0, 0, 0, 1],
    [1, 1, 1, 1, 1, 1]
]

# 标签：0表示X，1表示O
labels = np.array([0, 1])

# 将数据和标签组合
data = np.array([X_pattern, O_pattern])

def convolution(image, kernel):
    """
    实现简单的卷积操作
    :param image: 输入图像 (6x6)
    :param kernel: 卷积核 (3x3)
    :return: 卷积后的特征图 (4x4)
    """
    kernel_size = kernel.shape[0]
    output_size = image.shape[0] - kernel_size + 1
    output = np.zeros((output_size, output_size))

    for i in range(output_size):
        for j in range(output_size):
            output[i, j] = np.sum(image[i:i+kernel_size, j:j+kernel_size] * kernel)
    return output

def max_pooling(feature_map, pool_size=2):
    """
    实现最大池化操作
    :param feature_map: 输入特征图 (4x4)
    :param pool_size: 池化窗口大小 (2x2)
    :return: 池化后的特征图 (2x2)
    """
    output_size = feature_map.shape[0] // pool_size
    output = np.zeros((output_size, output_size))

    for i in range(0, feature_map.shape[0], pool_size):
        for j in range(0, feature_map.shape[1], pool_size):
            output[i//pool_size, j//pool_size] = np.max(feature_map[i:i+pool_size, j:j+pool_size])
    return output

def softmax(x):
    """
    实现Softmax函数
    :param x: 输入向量
    :return: 概率分布
    """
    exp_x = np.exp(x - np.max(x))  # 防止数值不稳定
    return exp_x / np.sum(exp_x)

def fully_connected(features, weights, bias):
    """
    实现全连接层
    :param features: 输入特征向量
    :param weights: 权重矩阵
    :param bias: 偏置向量
    :return: 输出向量
    """
    return np.dot(features, weights) + bias

def cross_entropy_loss(y_true, y_pred):
    """
    计算交叉熵损失
    :param y_true: 真实标签 (one-hot编码)
    :param y_pred: 预测概率
    :return: 损失值
    """
    return -np.sum(y_true * np.log(y_pred))

def backward_propagation(features, weights, bias, y_true, y_pred):
    """
    实现反向传播
    :param features: 输入特征向量
    :param weights: 权重矩阵
    :param bias: 偏置向量
    :param y_true: 真实标签 (one-hot编码)
    :param y_pred: 预测概率
    :return: 更新后的权重和偏置
    """
     # 计算梯度
    d_loss = y_pred - y_true  # 形状为 (2,)
    d_loss = d_loss.reshape(1, -1)  # 转换为行向量 (1, 2)

    features = features.reshape(-1, 1)  # 转换为列向量 (4, 1)

    # 计算权重梯度
    d_weights = np.dot(features, d_loss)  # (4, 1) @ (1, 2) -> (4, 2)

    # 计算偏置梯度
    d_bias = np.sum(d_loss, axis=0)  # (2,)

    # 学习率
    learning_rate = 0.01

    # 更新权重和偏置
    weights -= learning_rate * d_weights
    bias -= learning_rate * d_bias

    return weights, bias

if __name__ == "__main__":
    # 定义卷积核（随机初始化）
    kernel = np.random.randn(3, 3)

    # 定义全连接层的权重和偏置（随机初始化）
    weights = np.random.randn(4, 2)  # 4个输入特征，2个输出类别
    bias = np.random.randn(2)

    # 训练和预测
    for epoch in range(1000):  # 训练1000个epoch
        for i, image in enumerate(data):
            # 卷积
            conv_output = convolution(image, kernel)
            # 池化
            pool_output = max_pooling(conv_output)
            # 展平
            flattened = pool_output.flatten()
            # 全连接
            logits = fully_connected(flattened, weights, bias)
            # Softmax
            probabilities = softmax(logits)
            # 真实标签 (one-hot编码)
            y_true = np.zeros(2)
            y_true[labels[i]] = 1
            # 计算损失
            loss = cross_entropy_loss(y_true, probabilities)
            # 反向传播
            weights, bias = backward_propagation(flattened, weights, bias, y_true, probabilities)

        if epoch % 10 == 0:
            print(f"Epoch {epoch}, Loss: {loss}")

    # 预测
    for i, image in enumerate(data):
        conv_output = convolution(image, kernel)
        pool_output = max_pooling(conv_output)
        flattened = pool_output.flatten()
        logits = fully_connected(flattened, weights, bias)
        probabilities = softmax(logits)
        prediction = np.argmax(probabilities)
        print(f"Input {i+1}: Predicted class {prediction}, Actual class {labels[i]}")
