<?php

namespace AB\ParallelTestingBundle\Entity;

use Doctrine\ORM\Mapping as ORM;

/**
 * Test
 *
 * @ORM\Table()
 * @ORM\Entity(repositoryClass="AB\ParallelTestingBundle\Entity\TestRepository")
 */
class Test
{
    /**
     * @var integer
     *
     * @ORM\Column(name="id", type="integer")
     * @ORM\Id
     * @ORM\GeneratedValue(strategy="AUTO")
     */
    private $id;

    /**
     * @var string
     *
     * @ORM\Column(name="type", type="string", length=255)
     */
    private $type;

    /**
     * @var integer
     *
     * @ORM\Column(name="lowerLimit", type="integer")
     */
    private $lowerLimit;

    /**
     * @var integer
     *
     * @ORM\Column(name="upperLimit", type="integer")
     */
    private $upperLimit;

    /**
     * @var string
     *
     * @ORM\Column(name="status", type="string", length=255)
     */
    private $status;

    /**
     * @var string
     *
     * @ORM\Column(name="programOutput", type="text")
     */
    private $programOutput;

    /**
     * @var string
     *
     * @ORM\Column(name="fullCommand", type="string", length=500)
     */
    private $fullCommand;

    /**
     * @var string
     *
     * @ORM\Column(name="systemRunTime", type="string", length=255)
     */
    private $systemRunTime;

    /**
     * @var string
     *
     * @ORM\Column(name="clockRunTime", type="string", length=255)
     */
    private $clockRunTime;

    /**
     * @var string
     *
     * @ORM\Column(name="cpuPercent", type="string", length=255)
     */
    private $cpuPercent;


    /**
     * Get id
     *
     * @return integer 
     */
    public function getId()
    {
        return $this->id;
    }

    /**
     * Set type
     *
     * @param string $type
     * @return Test
     */
    public function setType($type)
    {
        $this->type = $type;

        return $this;
    }

    /**
     * Get type
     *
     * @return string 
     */
    public function getType()
    {
        return $this->type;
    }

    /**
     * Set lowerLimit
     *
     * @param integer $lowerLimit
     * @return Test
     */
    public function setLowerLimit($lowerLimit)
    {
        $this->lowerLimit = $lowerLimit;

        return $this;
    }

    /**
     * Get lowerLimit
     *
     * @return integer 
     */
    public function getLowerLimit()
    {
        return $this->lowerLimit;
    }

    /**
     * Set upperLimit
     *
     * @param integer $upperLimit
     * @return Test
     */
    public function setUpperLimit($upperLimit)
    {
        $this->upperLimit = $upperLimit;

        return $this;
    }

    /**
     * Get upperLimit
     *
     * @return integer 
     */
    public function getUpperLimit()
    {
        return $this->upperLimit;
    }

    /**
     * Set status
     *
     * @param string $status
     * @return Test
     */
    public function setStatus($status)
    {
        $this->status = $status;

        return $this;
    }

    /**
     * Get status
     *
     * @return string 
     */
    public function getStatus()
    {
        return $this->status;
    }

    /**
     * Set programOutput
     *
     * @param string $programOutput
     * @return Test
     */
    public function setProgramOutput($programOutput)
    {
        $this->programOutput = $programOutput;

        return $this;
    }

    /**
     * Get programOutput
     *
     * @return string 
     */
    public function getProgramOutput()
    {
        return $this->programOutput;
    }

    /**
     * Set fullCommand
     *
     * @param string $fullCommand
     * @return Test
     */
    public function setFullCommand($fullCommand)
    {
        $this->fullCommand = $fullCommand;

        return $this;
    }

    /**
     * Get fullCommand
     *
     * @return string 
     */
    public function getFullCommand()
    {
        return $this->fullCommand;
    }

    /**
     * Set systemRunTime
     *
     * @param string $systemRunTime
     * @return Test
     */
    public function setSystemRunTime($systemRunTime)
    {
        $this->systemRunTime = $systemRunTime;

        return $this;
    }

    /**
     * Get systemRunTime
     *
     * @return string 
     */
    public function getSystemRunTime()
    {
        return $this->systemRunTime;
    }

    /**
     * Set clockRunTime
     *
     * @param string $clockRunTime
     * @return Test
     */
    public function setClockRunTime($clockRunTime)
    {
        $this->clockRunTime = $clockRunTime;

        return $this;
    }

    /**
     * Get clockRunTime
     *
     * @return string 
     */
    public function getClockRunTime()
    {
        return $this->clockRunTime;
    }

    /**
     * Set cpuPercent
     *
     * @param string $cpuPercent
     * @return Test
     */
    public function setCpuPercent($cpuPercent)
    {
        $this->cpuPercent = $cpuPercent;

        return $this;
    }

    /**
     * Get cpuPercent
     *
     * @return string 
     */
    public function getCpuPercent()
    {
        return $this->cpuPercent;
    }
}
