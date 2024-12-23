# TOC
- [1.17.1（TBD）](#1.17.1)
- [1.17](#1.17（2024/12/23）)
- [1.16.2](#1.16.2（2024/10/19）)
- [1.16.1](#1.16.1（2024/10/2）)
- [1.16](#1.16（2024/9/6）)
- [1.15.3](#1.15.3（2024/1/25）)
- [1.15.2](#1.15.2（2023/11/24）)
- [1.15.1](#1.15.1（2023/11/22）)
- [1.15.0](#1.15.0（2023/10/27）)
- [1.14.3](#1.14.3（2023/10/22）)

## 1.17.1

### 改动

待定。

### 兼容性

兼容 1.17.x 。

## 1.17（2024/12/23）

### 新增内容

- `Animation` 类新增 `Type` 成员和 `SetFramesForLayer()` 成员函数。
- `ZombieUpdateActionEvent` 事件，对应僵尸行为动作的更新。
- `ZombieUpdatePlayingEvent` 事件，被冻结、黄油定身时也会触发的存活僵尸的更新。
- `PlantUpdateAbilityEvent` 事件，植物技能的更新事件。
- `Resource` 类，含有对应资源对象的静态成员变量。
  - 需要用 `InitImages()` 初始化。
- `Matrix3` 类，用于存储一个三维矩阵。
  - 含有 `ScaleRotateTransformMatrix()` 成员函数，用于将当前类变为指定变换的变换矩阵。
- `Board` 新增 `TakeSunMoney()` 成员函数，用于自动判断阳光是否足够的同时扣除阳光。

### 改动

- `Injector` 重做。现在它的代码必须在构造时就指明，不能动态更换。
- 枚举 `ZombieAccessoriesType1` 被更名为 `HelmType`。
- `TrackInstance` 现在是 `BaseClass` 的派生类。
- `Animation::AttachTo()` 调整了参数，使其现在可以容易地使用。
- `PlantSquishEvent` 现在是 `DLLEvent` 的派生类。
- `CollisionBox` 重做为 `Rect` 类，可以较方便地判定矩形覆盖。

### 移除内容

- `CT` 文件夹。
- 枚举 `CardType` 和 `PlantType`。它们现在是 `SeedType` 的别名。

### 兼容性

- 由于 Enum 方面的改动，可能出现不兼容 1.16.x 的情况。如果遇到相关问题，请在 issue 汇报。

## 1.16.2（2024/10/19）

### 新增内容

- `Image` 类，用于访问内存中的图片。
- `StoreItem` 枚举，对应商店售卖物品的编号。
- `Miscellaneous` 新增 `IZSquishBrain()`，压扁指定脑子。
- `Animation` 类新增 `SetImageOverride()`，可以令动画重载贴图。

### 改动

- `SaveData`，`Widget`，`AttachEffect`，`Mouse`，`Music` 现在是 `BaseClass` 的派生类。
- `GameObject`，`Plant`，`Miscellaneous` 新增成员。
- `SaveData` 现在可以读写指定模式的通关纪录和指定商店物品的购买量。

### 漏洞修复

- 修复 `Plant::SetMemSize()` 会导致图鉴易崩溃的漏洞。

### 兼容性

- **不考虑兼容** 1.16.x 及以前的版本。

## 1.16.1（2024/10/2）

### 新增内容

- `ReadMemory()` 等函数的地址现在使用 DWORD 表示内存地址。
- 添加了以下新事件：
  - Board 游戏更新事件 `BoardUpdateGameEvent`；
  - 小推车启动事件 `LawnmowerStartEvent`；
  - IZ 关卡完成事件 `IZLevelCompleteEvent`；
  - IZ 关卡初始化后的事件 `IZLevelStartAfterEvent`；
  - IZ 食脑事件`IZScoreBrainEvent`。
- `PuzzlePhaseCompleteEvent` 现在由 `DLLEvent` 派生，`dll` 中函数名为 `onPuzzlePhaseComplete()`。

### 兼容性

- 大部分兼容 1.16。

## 1.16（2024/9/6）

### 新增内容

- 重做了事件机制。现在使用 `DLLEvent` 实现事件处理功能。
  - 目前大部分事件已转变为 `DLLEvent` 形式。\
- 添加了 `Dialog` 组件、编辑框组件、`List` 控件和 `CheckBox` 控件的控制功能。
- 对部分代码文件进行分类。 
- 新增保存和读取存档的功能。
- 新增若干事件。

### 漏洞修复

- 修复 `Board::GetAllLawnmowers()` 无法获取任何小推车的漏洞。

### 兼容性

- **不考虑兼容** 1.15.3 及以前的版本。

## 1.15.3（2024/1/25）

### 漏洞修复

- 修复 `ChallengePage` 相关的一系列问题。
- 修复部分代码文件使用 UTF-8（无签名）的问题。

### 兼容性

- 兼容 1.15.x。
- **不兼容** 1.14.3 及以前的版本。

## 1.15.2（2023/11/24）

### 新增内容

- `ChallengeScreen` 类，用于处理选关界面。
- `VaseOpenEvent` 类，罐子被打开的事件。
- `UpdateGameObjectsEvent` 类，更新游戏内物品的事件。
- `PlantSquishEvent` 类，植物被碾压的事件。
- `ImitaterPlantEvent` 类，模仿者生成新植物的事件。
- `ChallengePage` 枚举，用于表示选关界面的页数。

### 兼容性

- 兼容 1.15.x。
- **不兼容** 1.14.3 及以前的版本。

## 1.15.1（2023/11/22）

### 新增内容

- `ThreeState` 枚举，用于三态判断。
- `Miscellaneous` 类添加了 `SetMemSize()`，用于扩展该类。
- `Extensions.h` 添加 `EnableVaseBreak()`，可以启用砸罐子模式的部分特性。
- `Const::GetLevelScene()` 和 `Const::SetLevelScene`，用于获取/设置模式的默认关卡。
- `Flags.h`，包含 `DamageRangeFlags` 和 `DamageFlags`，用于存储状态压缩存储的量。
- `Zombie` 类添加了 `Hit()` 和 `HitDirect()` 的 `DamageFlags` 适配版。
- `Zombie` 类添加了 `EffectedBy()`，用于判定僵尸是否符合某些条件。
- `PVZApp` 类添加若干属性。

### 改动

- 平台工具集从 `v142` 更新至 `v143`。
- `Events` 组件现在支持 `x64` 构建。
- `Events` 组件的部分功能分拆到 `.cpp` 文件中。
- 使用 `Creator::CreateZombie()` 生成的僵王博士将被强制生成在 0 行 0 列。
- 更新 `README.md` 的过时内容。
- `Memory` 类现在使用新的方式实现 `Execute()`，可用 `immediateExecute` 控制是否不等待 `Board` 更新就执行指令。
- 优化 `Memory::Variable` 的注释。

### 漏洞修复

- 修复 `Const::WriteCoinValue()` 不能正确修改小阳光价值的漏洞。
- 修复 `Zombie::canDecelerate()` 无法正常判定的漏洞。

### 兼容性

- 兼容 1.15.0。
- **不兼容** 1.14.3 及以前的版本。

## 1.15.0（2023/10/27）

### 新增内容

- `PVZApp` 类，用于处理 `PVZ_BASE` 偏移的属性。
- `PVZutil` 类，用于存放部分功能，目前只支持版本查询。
- `BaseClass` 类，作为大部分类的基类，提供只读基址和简单构造函数。

### 改动

- 将 `PVZ` 从类转换为命名空间。
  - 原本的属性均已转移到其他类的定义之下。
  - `PVZ.h` 中的四个结构体均移入 `PVZ` 命名空间内部。
  - 需要 `PVZ` 对象作为参数的函数均已更新。
- 根据 `PVZ` 命名空间的改动，更新 `README.md`。

### 漏洞修复

- 修复 `CALC_PTR_ADDR` 宏不能正确指定运算类型的漏洞。
- 修复某些情况下无法初始化 pvzclass 的漏洞。

### 兼容性

- **不兼容** 1.14.3 及以前的版本。

## 1.14.3（2023/10/22）
- 大重构前的最后一个稳定版本。